/*
  usb to serial converter
*/

#define BAUDRATE 115200

void setup() {
  
  // Serial port to communicate via USB CDC
  Serial.begin(BAUDRATE);
  
  // Serial1 port to communicate via TTL (pin 0 [RX], pin 1 [TX])
  Serial1.begin(BAUDRATE);
  
  // wait for USB port to connect
  while(!Serial) {
    ;
  }
}

void loop() {

  // copy data from USB to TTL
  if (Serial.available()) {
    Serial1.write(Serial.read());
  }
  
  // copy data from TTL to USB
  if (Serial1.available()) {
    Serial.write(Serial1.read());
  }
}

