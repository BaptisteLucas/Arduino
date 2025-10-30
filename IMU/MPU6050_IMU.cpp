#include "MPU6050_IMU.h"
#include "Wire.h"

MPU6050_IMU::MPU6050_IMU() : dmpReady(false) {}

bool MPU6050_IMU::begin() {
    Wire.begin();
    mpu.initialize();
    devStatus = mpu.dmpInitialize();

    if (devStatus != 0) {
        return false;
    }

    mpu.setDMPEnabled(true);
    dmpReady = true;
    packetSize = mpu.dmpGetFIFOPacketSize();
    return true;
}

bool MPU6050_IMU::update() {
    if (!dmpReady) return false;

    mpuIntStatus = mpu.getIntStatus();
    fifoCount = mpu.getFIFOCount();

    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        mpu.resetFIFO();
        return false;
    } else if (mpuIntStatus & 0x02) {
        while (fifoCount < packetSize) {
            fifoCount = mpu.getFIFOCount();
        }

        mpu.getFIFOBytes(fifoBuffer, packetSize);
        fifoCount -= packetSize;

        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
        return true;
    }
    return false;
}

float MPU6050_IMU::getYawDegrees() { return ypr[0] * 180 / M_PI; }
float MPU6050_IMU::getPitchDegrees() { return ypr[1] * 180 / M_PI; }
float MPU6050_IMU::getRollDegrees() { return ypr[2] * 180 / M_PI; }
float MPU6050_IMU::getYawRadians() { return ypr[0]; }
float MPU6050_IMU::getPitchRadians() { return ypr[1]; }
float MPU6050_IMU::getRollRadians() { return ypr[2]; }
