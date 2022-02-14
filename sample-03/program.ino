const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;
const int DISPLAY_TIME = 500;

void setup()
{
 pinMode(RED_PIN, OUTPUT);
 pinMode(GREEN_PIN, OUTPUT);
 pinMode(BLUE_PIN, OUTPUT);
}

void loop()
{
 mainColors();
 // showSpectrum();
}

void mainColors()
{
 digitalWrite(RED_PIN, LOW);
 digitalWrite(GREEN_PIN, LOW);
 digitalWrite(BLUE_PIN, LOW);
 delay(DISPLAY_TIME);
 digitalWrite(RED_PIN, HIGH);
 digitalWrite(GREEN_PIN, LOW);
 digitalWrite(BLUE_PIN, LOW);
 delay(DISPLAY_TIME);
 digitalWrite(RED_PIN, LOW);
 digitalWrite(GREEN_PIN, HIGH);
 digitalWrite(BLUE_PIN, LOW);
 delay(DISPLAY_TIME);
 digitalWrite(RED_PIN, LOW);
 digitalWrite(GREEN_PIN, LOW);
 digitalWrite(BLUE_PIN, HIGH);
 delay(DISPLAY_TIME);


 digitalWrite(RED_PIN, HIGH);
 digitalWrite(GREEN_PIN, HIGH);
 digitalWrite(BLUE_PIN, LOW);
 delay(DISPLAY_TIME);

 digitalWrite(RED_PIN, LOW);
 digitalWrite(GREEN_PIN, HIGH);
 digitalWrite(BLUE_PIN, HIGH);
 delay(DISPLAY_TIME);

 digitalWrite(RED_PIN, HIGH);
 digitalWrite(GREEN_PIN, LOW);
 digitalWrite(BLUE_PIN, HIGH);
 delay(DISPLAY_TIME);
}
void showSpectrum()
{
 for (int x = 0; x <= 767; x++)
 {
 RGB(x);
 delay(10);
 }
}

void RGB(int color)
{
 int redIntensity;
 int greenIntensity;
 int blueIntensity;
 color = constrain(color, 0, 767);
if (color <= 255)
 {
 redIntensity = 255 - color;
greenIntensity = color;
 blueIntensity = 0;
 }
 else if (color <= 511)
 {
 redIntensity = 0;
 greenIntensity = 511 - color;
 blueIntensity = color - 256;
 }
 else
 {
 redIntensity = color - 512;
 greenIntensity = 0;
 blueIntensity = 767 - color;
 }

 analogWrite(RED_PIN, redIntensity);
 analogWrite(GREEN_PIN, greenIntensity);
 analogWrite(BLUE_PIN, blueIntensity);
}