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

// define variables
int redValue = 255;
int greenValue = 0;
int blueValue = 0;

/**
 * Fonction pour faire un fondu entre deux couleurs.
 * @param decreasingColor: Pointeur vers la variable de la couleur à diminuer.
 * @param increasingColor: Pointeur vers la variable de la couleur à augmenter.
 * @param decreasingPin: Broche de la couleur à diminuer.
 * @param increasingPin: Broche de la couleur à augmenter.
 */
void fadeBetweenColors(int *decreasingColor, int *increasingColor, int decreasingPin, int increasingPin) {
  for (int i = 0; i < 255; i += 1) {
    *decreasingColor -= 1;
    *increasingColor += 1;
    analogWrite(decreasingPin, *decreasingColor);
    analogWrite(increasingPin, *increasingColor);
    delay(delayTime);
  }
}

// main loop
void loop()
{
  // Fondu du rouge vers le vert
  fadeBetweenColors(&redValue, &greenValue, RED, GREEN);

  // Fondu du vert vers le bleu
  fadeBetweenColors(&greenValue, &blueValue, GREEN, BLUE);

  // Fondu du bleu vers le rouge
  fadeBetweenColors(&blueValue, &redValue, BLUE, RED);
}

