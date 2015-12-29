# Photon-DHT22
Configures a DHT22 humidity/temp sensor to work with a Particle Photon and publish readings to the Particle Dashboard.

I've included a copy of the PietteTech_DHT library, feel free to grab a more recent copy and replace what is bundled in if it's outdated.

The connection setup for the DHT22 is as follows...

* PIN 1 = 3.3V or 5V
* PIN 2 = Data (D1 is default for this project)
* PIN 3 = Unused
* PIN 4 = Ground

Between PIN 1 and PIN 2 I'm running a 10K pulldown resistor

Note: I did run into issues when trying to use D0 to connect to the DHT22 even though the library says it's supported.
