#include <SPI.h>

int value = 0;
int d = 50;

int LED1 = 12;
int LED2 = 11;
int LED3 = 10;
int LED4 = 9;

void setup(){
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  
  SPCR |= bit(SPE); // Configura modo escravo

  pinMode(MISO, OUTPUT); // Pino MISO para saída
  pinMode(MOSI, INPUT); // Pino MOSI como entrada

  SPI.attachInterrupt(); // Configura interrupção do SPI
}

// Função de interrupção
ISR (SPI_STC_vect){
  value = SPDR;
  Serial.println(value);
}

void loop (void){
  // Lógica para ligar os LEDs de acordo com o valor SPI
  if (value == 1){
    LED1 = HIGH;
    LED2 = LOW;
    LED3 = LOW;
    LED4 = LOW;
  } else if (value == 2) {
    LED1 = LOW;
    LED2 = HIGH;
    LED3 = LOW;
    LED4 = LOW;
  } else if (value == 4) {
    LED1 = LOW;
    LED2 = LOW;
    LED3 = HIGH;
    LED4 = LOW;
  } else if (value == 8) {
    LED1 = LOW;
    LED2 = LOW;
    LED3 = LOW;
    LED4 = HIGH;
  } else {
    //Serial.println("Valor invalido");
  }
}
