#define BLUE 3
#define GREEN 5
#define RED 6
#define delayTime 10 // fading time between colors

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

/**
 * Fonction pour faire un fondu entre deux couleurs.
 * @param decreasingPin: Broche de la couleur à diminuer.
 * @param increasingPin: Broche de la couleur à augmenter.
 */
void fadeBetweenColors(int decreasingPin, int increasingPin) {
  int decreasingColor = 255;
  int increasingColor = 0;
  
  for (int i = 0; i < 255; i += 1) {
    decreasingColor -= 1;
    increasingColor += 1;
    analogWrite(decreasingPin, decreasingColor);
    analogWrite(increasingPin, increasingColor);
    delay(delayTime);
  }
}

// main loop
void loop()
{
  // Fondu du rouge vers le vert
  fadeBetweenColors(RED, GREEN);

  // Fondu du vert vers le bleu
  fadeBetweenColors(GREEN, BLUE);

  // Fondu du bleu vers le rouge
  fadeBetweenColors(BLUE, RED);
}

