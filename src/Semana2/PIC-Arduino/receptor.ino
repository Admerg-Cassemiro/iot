void setup() {
  // Recepção via comunicação serial UART 8N1 9600bps, RX2
  Serial2.begin(9600);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  byte x = Serial2.read();
  if (x == 0x49){
    digitalWrite(13,HIGH);
  } else {
    digitalWrite(13,LOW);
  }
  Serial.println(x);
} 
