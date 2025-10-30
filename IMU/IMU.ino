#include <Wire.h>
#include "MPU6050_IMU.h"

MPU6050_IMU imu;

void setup() {
    Serial.begin(115200);
    if (!imu.begin()) {
        Serial.println("Erreur initialisation MPU6050 !");
        while (1);
    }
}

void loop() {
    if (imu.update()) {
        Serial.print("Yaw: ");
        Serial.print(imu.getYawDegrees());
        Serial.print("°\tPitch: ");
        Serial.print(imu.getPitchDegrees());
        Serial.print("°\tRoll: ");
        Serial.print(imu.getRollDegrees());
        Serial.println("°");
    }
    delay(100);
}
