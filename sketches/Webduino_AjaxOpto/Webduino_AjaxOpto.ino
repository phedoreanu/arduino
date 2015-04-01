#include "Bounce2.h"
#include "SPI.h"
//#include "SD.h"
#include "Ethernet.h"
#include "WebServer.h"

// 1st opto
const int opto_pin = 2;

// 2nd opto
const int opto2_pin = 4;

// override hardware switch
const int switch_pin = 3;

// green led
const int led1_pin = 5;

// red led
const int led2_pin = 7;

// initializing the debouncer
Bounce debouncer = Bounce();

// CHANGE THIS TO YOUR OWN UNIQUE VALUE
static uint8_t mac[6] = { 0x3A, 0xDB, 0x87, 0x78, 0x37, 0xE5 };

// CHANGE THIS TO MATCH YOUR HOST NETWORK
static uint8_t ip[4] = { 192, 168, 0, 210 }; // area 51!

/* all URLs on this server will start with /buzz because of how we
 * define the PREFIX value.  We also will listen on port 80, the
 * standard HTTP service port */
#define PREFIX ""
WebServer webserver(PREFIX, 80);

/* the piezo speaker on the Danger Shield is on PWM output pin #3 */
#define BUZZER_PIN 8

/* toggle is used to only turn on the speaker every other loop
iteration. */
char toggle = 0;

/* This command is set as the default command for the server.  It
 * handles both GET and POST requests.  For a GET, it returns a simple
 * page with some buttons.  For a POST, it saves the value posted to
 * the buzzDelay variable, affecting the output of the speaker */
void buzzCmd(WebServer &server, WebServer::ConnectionType type, char *, bool) {
  if (type == WebServer::POST) {
    bool repeat;
    char name[16], value[16];
    do {
      /* readPOSTparam returns false when there are no more parameters
       * to read from the input.  We pass in buffers for it to store
       * the name and value strings along with the length of those
       * buffers. */
      repeat = server.readPOSTparam(name, 16, value, 16);

      /* this is a standard string comparison function.  It returns 0
       * when there's an exact match.  We're looking for a parameter
       * named "buzz" here. */
      if (strcmp(name, "light_switch") == 0) {
        /* use the STRing TO Unsigned Long function to turn the string
         * version of the delay number into our integer buzzDelay
         * variable */
        int light_value = strtoul(value, NULL, 10);
        switch (light_value) {
          case 0:
            light(opto_pin, LOW);
            break;
          case 1:
            light(opto_pin, HIGH);
            break;
        }
      }
    } while (repeat);

    // after procesing the POST data, tell the web browser to reload
    // the page using a GET method.
    server.httpSeeOther(PREFIX);
    return;
  }

  /* for a GET or HEAD, send the standard "it's all OK headers" */
  server.httpSuccess();

  /* we don't output the body for a HEAD request */
  if (type == WebServer::GET) {
    /* store the HTML in program memory using the P macro */
    P(message) =
      "<!DOCTYPE html><html><head>"
      "<title>Webduino AJAX Opto Example</title>"
      "<link href='https://code.jquery.com/ui/1.9.2/themes/base/jquery-ui.css' rel=stylesheet />"
      "<link href='http://olance.github.io/jQuery-switchButton/jquery.switchButton.css' rel=stylesheet />"
      //"<meta http-equiv='Content-Script-Type' content='text/javascript'>"
      "<script src='https://code.jquery.com/jquery-1.11.0.min.js'></script>"
      "<script src='https://code.jquery.com/ui/1.10.4/jquery-ui.min.js'></script>"
      "<script src='http://olance.github.io/jQuery-switchButton/jquery.switchButton.js'></script>"
      "<style> .switch-button-label { font-size: 34px; } </style>"
      "<script>"
      "$(document).ready(function(){ $('input[type=checkbox]').switchButton({width: 130, height: 40, button_width: 80}).change(function(){"
      "light_value = $(this).prop('checked') ? 1 : 0;"
      "$.post('/', { light_switch: light_value } );"
      "	}); });"
      "</script>"
      "</head>"
      "<body style='font-size:62.5%;'>"
      "<h1>Test the Lights!</h1>"
      "<input type=checkbox >"
      "</body>"
      "</html>";
    server.printP(message);
  }
}

void blink_led(const int led_pin, const int miliseconds) {
  digitalWrite(led_pin, HIGH);
  delay(miliseconds);
  digitalWrite(led_pin, LOW);
}

void light(const int pin, const int new_state) {
  digitalWrite(pin, new_state);
  if (new_state == HIGH) {
    blink_led(led1_pin, 100);
    Serial.println("LED on");
  } else {
    blink_led(led2_pin, 100);
    Serial.println("LED off");
  }
}

void setup() {
  // set pins to OUTPUT
  pinMode(opto_pin, OUTPUT);
  pinMode(opto2_pin, OUTPUT);
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);

  // initialize switch
  pinMode(switch_pin, INPUT);
  digitalWrite(switch_pin, HIGH);
  debouncer.attach(switch_pin);
  debouncer.interval(50);

  // set the PWM output for the buzzer to out
  pinMode(BUZZER_PIN, OUTPUT);

  // setup the Ehternet library to talk to the Wiznet board
  Ethernet.begin(mac);

  /* register our default command (activated with the request of
   * http://x.x.x.x/buzz */
  webserver.setDefaultCommand(&buzzCmd);

  /* start the server to wait for connections */
  webserver.begin();
}

void loop() {
  // detecting falling edge
  if (debouncer.update() && debouncer.read() == LOW) {
    if (digitalRead(opto_pin) == HIGH) {
      light(opto_pin, LOW);
      light(opto2_pin, LOW);
    } else {
      light(opto_pin, HIGH);
      light(opto2_pin, HIGH);
    }
  }

  // process incoming connections one at a time forever
  webserver.processConnection();

  /* every other time through the loop, turn on and off the speaker if
   * our delay isn't set to 0. */
  /*if ((++toggle & 1) && (buzzDelay > 0)) {
    digitalWrite(BUZZER_PIN, HIGH);
    delayMicroseconds(buzzDelay);
    digitalWrite(BUZZER_PIN, LOW);
  }*/
}
