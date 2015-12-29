// This #include statement was automatically added by the Particle IDE.
#include "PietteTech_DHT.h"

// DHT parameters
#define DHTTYPE  DHT22              // Sensor type DHT11/21/22/AM2301/AM2302
#define DHTPIN   D1         	    // Digital pin for communications
#define DHT_SAMPLE_INTERVAL   2000  // Sample every two seconds

// Variables
int temperature;
int humidity;
int blue = D7;

//declaration
void dht_wrapper(); // must be declared before the lib initialization

// Lib Initialize
PietteTech_DHT DHT(DHTPIN, DHTTYPE, dht_wrapper);

// globals
unsigned int DHTnextSampleTime;	    // Next time we want to start sample
bool bDHTstarted;		    // flag to indicate we started acquisition
int n;                              // counter

void setup() {
    pinMode(blue, OUTPUT);
    DHTnextSampleTime = 0;

}

void dht_wrapper() {
    DHT.isrCallback();
}

void loop()
{
  // Check if we need to start the next sample
  if (millis() > DHTnextSampleTime) {
	if (!bDHTstarted) {		// start the sample
	    DHT.acquire();
	    bDHTstarted = true;
	}

    if (!DHT.acquiring()) {		// has sample completed?

    // get DHT status
    int result = DHT.getStatus();
    int humidity = DHT.getHumidity();
    int tempf = DHT.getFahrenheit();
    int tempc = DHT.getCelsius();
    int tempk = DHT.getKelvin();
    int dp = DHT.getDewPoint();
    int dpslow = DHT.getDewPointSlow();

    digitalWrite(blue, HIGH);
    Particle.publish("Humidity", String(humidity) + "%");
    Particle.publish("Temperature", String(tempf) + " °F");
    //Particle.publish("Dew Point", String(dpslow) + " %");

    delay(250);
    digitalWrite(blue, LOW);

    n++;  // increment counter
    bDHTstarted = false;  // reset the sample flag so we can take another
    DHTnextSampleTime = millis() + DHT_SAMPLE_INTERVAL;  // set the time for next sample
}
}
}
