#include "Bounce2.h"
#include "SPI.h"
#include "Ethernet.h"
#include "WebServer.h"
#include "dht11.h"

dht11 DHT11;
#define DHT11PIN 9

static uint8_t mac[6] = { 0x3A, 0xDB, 0x87, 0x78, 0x38, 0xE6 };

const int moisture_sensor_pin_1 = A0;
const int moisture_sensor_pin_2 = A4;
const int temp_sensor_pin = A2; //TMP36

const int enable_pin_pump_1 = 2; // connected to pin 1 on the H-bridge
const int enable_pin_pump_2 = 8; // connected to pin 9 on the H-bridge
const int switch_pin = 4;
const int led_pin = 6;

unsigned long last_reading_soil;
unsigned long last_reading_tmp36;
unsigned long last_reading_dht11;

float temperature = 0.0;
float h = 0.0;
float t = 0.0;

//unsigned int water_reserve_value = 0;
unsigned int soil_moisture_plant_1 = 0;
unsigned int soil_moisture_plant_2 = 0;

unsigned const int SOIL_WET_100 = 0;
unsigned const int SOIL_DRY_100 = 1023;
unsigned const int SOIL_MOISTURE = 550;

// initializing the debouncer
Bounce debouncer = Bounce();
volatile int state = LOW;    // the previous reading from the input pin

#define PREFIX ""
WebServer webserver(PREFIX, 80);

void helloCmd(WebServer &server, WebServer::ConnectionType type, char *, bool)
{
  /* this line sends the standard "we're all OK" headers back to the
     browser */
  //server.httpSuccess("text/html", "Refresh: 30");
  server.httpSuccess();

  /* if we're handling a GET or POST, we can output our data here.
     For a HEAD request, we just stop after outputting headers. */
  if (type == WebServer::GET)
  {
    /* this defines some HTML text in read-only memory aka PROGMEM.
     * This is needed to avoid having the string copied to our limited
     * amount of RAM. */

    /* this is a special form of print that outputs from PROGMEM */
    server.print("<title>Arduino watering system</title>");
    server.printf("<h3>Soil moisture 1: %d / pump %s</h3>", soil_moisture_plant_1, is_pump_on(enable_pin_pump_1) ? "ON" : "OFF");
    server.printf("<h3>Soil moisture 2: %d / pump %s</h3>", soil_moisture_plant_2, "N/A");

    server.print("<h3 style=color:orangered;>TMP36 Temperature: ");
    server.print(temperature);
    server.print("°C</h3>");

    server.print("<h3 style=color:royalblue;>DHT11 Humidity: ");
    server.print(h);
    server.print("%</h3>");

    server.print("<h3 style=color:green;>DHT11 Temperature: ");
    server.print(t);
    server.print("°C</h3>");
  }
}


void setup() {
  pinMode(enable_pin_pump_1, OUTPUT);
  //pinMode(enable_pin_pump_2, OUTPUT);
  // pull the enable pin LOW to start
  digitalWrite(enable_pin_pump_1, LOW);
  //digitalWrite(enable_pin_pump_2, LOW);

  pinMode(led_pin, OUTPUT);

  // initialize switch
  pinMode(switch_pin, INPUT);
  digitalWrite(switch_pin, HIGH);
  debouncer.attach(switch_pin);
  debouncer.interval(50);

  Ethernet.begin(mac);

  webserver.setDefaultCommand(&helloCmd);
  //webserver.addCommand("index.html", &helloCmd);
  webserver.begin();
}

void loop() {
  if (debouncer.update() && debouncer.read() == LOW) {
    activate_pump(enable_pin_pump_1, !state);
    //activate_pump(enable_pin_pump_2, !state);
    state = !state;
  }
  // once every 200 millis
  if ( millis() - last_reading_soil > 200 ) {
    last_reading_soil = millis();
    soil_moisture_plant_1 = analogRead(moisture_sensor_pin_1);
    soil_moisture_plant_2 = analogRead(moisture_sensor_pin_2);

    water_plant_one();
  }
  if ( millis() - last_reading_tmp36 > 1000 ) {
    last_reading_tmp36 = millis();
    get_temperature(); // TMP 36
  }
  char buff[64];
  int len = 64;

  /* process incoming connections one at a time forever */
  webserver.processConnection(buff, &len);

  if ( millis() - last_reading_dht11 > 1000 ) {
    last_reading_dht11 = millis();
    int chk = DHT11.read(DHT11PIN);
    h = DHT11.humidity;
    t = DHT11.temperature;
  }
}

long scaled_value(const float value) {
  float round_offset = value < 0 ? -0.5 : 0.5;
  return (long)(value * 100 + round_offset);
}

const float get_temperature() {
  const int sensor_voltage = analogRead(temp_sensor_pin);
  const float voltage = (sensor_voltage * 5.0) / 1024.0;
  temperature = (voltage - .5) * 100;
}

void activate_pump(const int pump_enable_pin, const int new_state) {
  digitalWrite(pump_enable_pin, new_state);
  digitalWrite(led_pin, new_state);
}

void activate_pump(const int pump_enable_pin) {
  activate_pump(pump_enable_pin, HIGH);
}

void deactivate_pump(const int pump_enable_pin) {
  activate_pump(pump_enable_pin, LOW);
}

void water_plant_one() {
  if (soil_moisture_plant_1 > SOIL_MOISTURE && !is_pump_on(enable_pin_pump_1)) {
    activate_pump(enable_pin_pump_1);
  } else if (soil_moisture_plant_1 > 400 && soil_moisture_plant_1 <= SOIL_MOISTURE
             && is_pump_on(enable_pin_pump_1)) {
    deactivate_pump(enable_pin_pump_1);
  }
}

bool is_pump_on(const int pin) {
  return digitalRead(pin) == HIGH ? true : false;
}
