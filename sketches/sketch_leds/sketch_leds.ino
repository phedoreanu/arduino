#include <Bounce2.h>

const int switch_pin = 4;

const int led1_pin = 6;
const int led2_pin = 5;
const int led_13_pin = 13;

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;

//int ledState = LOW;
//const unsigned int DEBOUNCE_DELAY = 5;
//Bounce debouncer = Bounce();

void setup() {
  // put your setup code here, to run once:
  pinMode(switch_pin, INPUT);
  digitalWrite(switch_pin, HIGH);

  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  pinMode(led_13_pin, OUTPUT);
  digitalWrite(led1_pin, LOW);
  digitalWrite(led2_pin, LOW);
  digitalWrite(led_13_pin, LOW);



  //  debouncer.attach(switch_pin);
  //debouncer.interval(DEBOUNCE_DELAY);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Detect the falling edge
  /*if (debouncer.update() && debouncer.read() == LOW) {
    blink_led(led1_pin, 100);
    blink_led(led2_pin, 100);
  }*/

}

void blink_led2(const int led_pin, long interval) {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(led_pin, ledState);
  }
}

