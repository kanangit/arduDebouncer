const int pinHiLo = 8;
const int pinLoHi = 9;
const int pinSwitch = 4;
bool flagPushed = false;
int buttonState = HIGH;
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pinHiLo, OUTPUT);
  pinMode(pinSwitch, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  flagPushed = false;
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(pinHiLo, HIGH);
  digitalWrite(pinLoHi, LOW);
  buttonState = digitalRead(pinSwitch);
  Serial.println(digitalRead(pinSwitch));
  if (flagPushed == false) {
    if (buttonState == LOW) {
      flagPushed = true;
      digitalWrite(pinHiLo, LOW);
      digitalWrite(pinLoHi, HIGH);
      delay(10);
      digitalWrite(pinHiLo, HIGH);
      digitalWrite(pinLoHi, LOW);
      delay(1000);
    }
  }

}
