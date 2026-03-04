
#include <ArduinoBLE.h> 

const char* MY_CUSTOM_SERVICE_UUID = "13a3af1e1def41c39dd17359ce281d44"; 
BLEService myCustomService(MY_CUSTOM_SERVICE_UUID);

/*TODO 1: Declare Characteristic UUID*/
const char* MY_READABLE_CHAR_UUID = "13a3af131def41c39dd17359ce281d44";
BLEIntCharacteristic myCharacteristic(MY_READABLE_CHAR_UUID, BLERead| BLEBroadcast);


/*TODO 2: Declare Advertising parameters */ 
const uint8_t completeRawAdvertisingData[] = {0x02,0x01,0x06,0x09,0xff,0x01,0x01,0x00,0x01,0x02,0x03,0x04,0x05};   

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
 
  /*TODO 3: Add the defined characteristic to the peripheral's GATT database*/
  myCustomService.addCharacteristic(myCharacteristic);


  BLE.addService(myCustomService);

  /*TODO 4: Build the advertising data packet*/
  BLEAdvertisingData advData;
  advData.setRawData(completeRawAdvertisingData, sizeof(completeRawAdvertisingData));  
  
  /*TODO 5:Copy set parameters in the actual advertising packet*/
  BLE.setAdvertisingData(advData);

  /*TODO 6: Build scan response data packet*/
  BLEAdvertisingData scanData;

  /*TODO 7:Copy set parameters in the actual scan response packet*/
    BLE.setScanResponseData(scanData);

  BLE.advertise();
  Serial.println("advertising ...");
}

void loop() {
  BLE.poll();
}