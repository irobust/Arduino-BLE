
#include <ArduinoBLE.h> 

/*TODO 1: Declare Service UUID*/
// You can generate one using online tools.https://www.uuidgenerator.net/
// Example format: "13a3af1e-1def-41c3-9dd1-7359ce281d44" (remove hyphens in code string)
const char* MY_CUSTOM_SERVICE_UUID = "13a3af1e1def41c39dd17359ce281d44"; 

/*TODO 2: Define your custom BLE Service*/
BLEService myCustomService(MY_CUSTOM_SERVICE_UUID);


void setup() {
 
  Serial.begin(9600);
  while (!Serial); 

  Serial.println("Starting BLE initialization...");

  if (!BLE.begin()) {
    Serial.println("ERROR: BLE initialization failed!");
    while (1);
  }

  Serial.println("BLE initialized successfully.");

  BLE.setLocalName("MyBLEDevice");
  Serial.println("Device name set.");
  Serial.println("BLE Peripheral is ready.");


  /* TODO 3: Add the defined service to the peripheral's GATT database*/
  BLE.addService(myCustomService);
  Serial.print("Added custom service with UUID: ");
  Serial.println(MY_CUSTOM_SERVICE_UUID);

  /* TODO 4: Start advertising.*/
  BLE.advertise();
  Serial.println("Advertising started.");

}

void loop() {

  BLE.poll();
}







