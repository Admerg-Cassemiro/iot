#include <SPI.h>

int value = 0;
int d = 50;

int LED1 = 12;
int LED2 = 11;
int LED3 = 10;
int LED4 = 9;

void setup(){
  Serial.begin(115200);
  
  SPCR |= bit(SPE); // Configura modo escravo

  pinMode(MISO, OUTPUT); // Pino MISO para saída
  pinMode(MOSI, INPUT); // Pino MOSI como entrada

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  SPI.attachInterrupt(); // Configura interrupção do SPI
}

// Função de interrupção
ISR (SPI_STC_vect){
  value = SPDR;
  Serial.println(value);
}

void loop(){
  // Lógica para ligar os LEDs de acordo com o valor SPI
  if (value == 1){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  } else if (value == 2) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  } else if (value == 4) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  } else if (value == 8) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
  } else {
    //Serial.println("Valor invalido");
  }
}
