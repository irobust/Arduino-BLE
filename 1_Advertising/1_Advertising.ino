
#include <ArduinoBLE.h> 

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Starting BLE initialization...");

  // Initialize the BLE library
  if (!BLE.begin()) {
    Serial.println("ERROR: BLE initialization failed!");
    // Stop here if BLE failed to initialize
    while (1);
  }

  Serial.println("BLE initialized successfully.");

  // Set the local name for the BLE device
  // This is the name that will appear during scanning
  BLE.setLocalName("MyBLEDevice");
  Serial.println("Device name set.");
  Serial.println("BLE Peripheral is ready.");


  /*TODO 1: Start advertising*/
  // Start advertising.
  // The simplest advertise() call automatically includes the device name and basic capabilities flags.
  // It uses the default advertising interval (often around 100ms).
  BLE.advertise();
  Serial.println("BLE Peripheral is now advertising.");
}

void loop() {

  /*TODO 2: Poll*/
  // In advertising mode, the peripheral primarily broadcasts.
  // We don't need to do much in the loop for simple advertising,
  // but calling poll() is good practice for handling potential future events like scan requests.
  BLE.poll();


}







