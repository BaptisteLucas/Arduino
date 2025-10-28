#define LED 3
#define delayTime 10 // fading time between colors

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

// define variables
int level = 0;
bool increase = true;

// main loop
void loop()
{
  // the level is tuned between 0 and 255 on each loop iteration
  if (increase) {
    level += 1;
    if (level >= 255) {
      increase = false;
    }
  }
  else {
    level -= 1;
    if (level <= 0) {
      increase = true;
    }
  }

  //the new level is applied to the LED
  analogWrite(LED, level);

  //a delay to make the fading visible
  delay(delayTime);
}

