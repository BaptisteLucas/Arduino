// Configuration des broches
#define PWM_OUT 3       // Broche PWM pour charger le condensateur
#define CONDO_INPUT A0  // Broche analogique pour mesurer la tension
#define CMD_DECH 2      // Broche numérique pour commander la décharge
#define BTN_INPUT 4    // Bouton de changement de rapport cyclique PWM 
#define delayTime 1    // loop delay time in milliseconds


int PWMRate = 25;       // Rapport cycle de charge PWM (0-100%)
float seuilCharge = 2.5; // Seuil de tension (en volts) où la charge est terminée
bool isCharging = false; // État de charge du condensateur

void setup() {
  pinMode(CMD_DECH, OUTPUT);  // Configure la broche de décharge en sortie
  digitalWrite(CMD_DECH, LOW); // Désactive la décharge

  pinMode(PWM_OUT, OUTPUT);   // Configure la broche PWM en sortie
  analogWrite(PWM_OUT, 0);  // Charge le condensateur avec le rapport cyclique défini

  pinMode(BTN_INPUT, INPUT_PULLUP);  // Broche en entrée avec résistance pull-up
  attachInterrupt(digitalPinToInterrupt(BTN_INPUT), Update_PWM_rate, FALLING);  // Interruption sur front descendant
  Serial.begin(9600);         // Initialisation du port série
}

// Fonction appelée quand l'interruption est déclenchée
void Update_PWM_rate() {
  PWMRate += 25;  // on augmente de 25% à chaque interruption
  if (PWMRate > 100) {
    PWMRate = 0;  // Reset à 0 si on dépasse 100%
  }
}

/**
 * Fonction qui lit une entrée analogique et retourne la tension en volts.
 * @param pin: Broche analogique à lire.
 */
float voltageReader(int pin) {
  int valeurAnalogique = analogRead(pin);
  return valeurAnalogique * (5.0 / 1023.0);  // Conversion en volts (résolution 10 bits)
                                                      // Le 5.0 permet d'avoir un résultat en float
}

// main loop
void loop() {
  
  if(!isCharging){
    // Si on n'est pas en charge
    digitalWrite(CMD_DECH, LOW); // Désactive la décharge
    analogWrite(PWM_OUT, PWMRate);  // Charge le condensateur avec le rapport cyclique défini
    isCharging = true;
  }
    
  // Lecture de la tension du condensateur en volts
  float tension = voltageReader(CONDO_INPUT);

  // Affichage de la tension
  Serial.print("Tension : ");
  Serial.print(tension);
  Serial.println(" V");

  // Gestion de la charge
  if (tension > seuilCharge) {
    // le condensateur est chargé
    analogWrite(PWM_OUT, 0); // Arrête la charge
    digitalWrite(CMD_DECH, HIGH);   // On décharge
    Serial.print("Ordre de décharge envoyé.\n");
  }

  delay(delayTime);  // Délai avant de reboucler  
}