TP pour mettre en oeuvre un bus I2C afin de communiquer avec une centrale inertielle :
- Alimentation 3.3V
- Connecter SCL et SDA

Utilisation de la librairie MPU6050 de J. Rowberg pour avoir un driver complet :
- Fusion de données interne au composant (DMP) -> améliore la précision
- Calcul des valeurs réelles à partir des données brutes
https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/MPU6050
Librairie enregistrée en respectant l'arborescence suivante:

IMU/
├── lib/
│   ├── I2Cdev/          # Dossier de la bibliothèque I2Cdev
│   │   ├── I2Cdev.h
│   │   └── I2Cdev.cpp
│   └── MPU6050/         # Dossier de la bibliothèque MPU6050
│       ├── MPU6050.h
│       └── MPU6050_6Axis_MotionApps20.h
├── MPU6050_IMU/         # Librairie personnalisée pour implémenter l'IMU
│   ├── MPU6050_IMU.h
│   └── MPU6050_IMU.cpp
└── IMU.ino              # Code principal

Attention, le fichier MPU6050.h est modifié en commentant la ligne
    //typedef MPU6050_Base MPU6050;
Cela créait un conflit à la compilation lors de l'utilisation des versions de driver MotionApps qui redéfinissent le type MPU6050

