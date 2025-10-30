#ifndef MPU6050_IMU_H
#define MPU6050_IMU_H

#include "lib/I2Cdev/I2Cdev.h"
#include "lib/MPU6050/MPU6050_6Axis_MotionApps612.h"

class MPU6050_IMU {
public:
    MPU6050_IMU();
    bool begin();
    bool update();
    float getYawDegrees();
    float getPitchDegrees();
    float getRollDegrees();
    float getYawRadians();
    float getPitchRadians();
    float getRollRadians();

private:
    MPU6050 mpu;
    bool dmpReady;
    uint8_t mpuIntStatus;
    uint8_t devStatus;
    uint16_t packetSize;
    uint16_t fifoCount;
    uint8_t fifoBuffer[64];
    Quaternion q;
    VectorFloat gravity;
    float ypr[3]; // yaw, pitch, roll en radians
};

#endif
