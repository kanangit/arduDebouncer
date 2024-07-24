const int pinHiLo = 9;
const int pinSwitch = 9;
bool flagPushed = false;
int buttonState = LOW;
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
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(pinHiLo, HIGH);
  buttonState = digitalRead(pinSwitch);
  //if (flagPushed == false) {
    if (buttonState == HIGH) {
      digitalWrite(pinHiLo, LOW);
    }
  //}
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
