# SEMANA 2

**Microcontroladores:**
- ATmega2560 (Arduino Mega 2560)
- PIC18F45K20

**Objetivos:**
- Programar o Arduino Mega para atuar como transmissor ou receptor de dados pela comunicação USART.
- Programar o PIC18F45K20 para atuar como transmissor ou receptor de dados pela comunicação USART.

**Descrição:**
Os experimentos dessa semana consistiam em realizar comunicação serial UART entre os dois microcontroladores, invertendo os papeis de transmissor e receptor nos dois experimentos. Ambos experimentos seguem a configuração UART 8N1.


## Experimento 1 (Arduino - PIC)

[![Experimento 1](./../../image/Semana2/Arduino-PIC/Arduino-PIC_GIF.gif)](./../../image/Semana2/Arduino-PIC/Arduino-PIC.jpg)

Nesse experimento, o Arduino deve ser programado como transmissor e o PIC como receptor dos dados:

- **Transmissão:** 
O Arduino irá ser configurado como transmissor(pino 16, TX2) a partir dos registradores no setup e irá ficar enviando alguns [código de caracteres](https://www.ime.usp.br/~pf/algoritmos/apend/ascii.html) para o PIC a cada segundo no loop. 

- **Recepção:**
O PIC irá ser configurado como receptor(pino RC7, RX) e irá verificar no loop( ```while(1){}``` ) se recebeu algum dado e dependendo do valor recebido ele irá ativar um pino respectivo no PORTD. O ideal é que os pinos do PORTD estejam ligados a LEDs para que se possa visualizar a recepção dos dados.

- **Resumo:** 
O Arduino irá transmitir a cada segundo um código que será recepcionado pelo PIC e ativará um respectivo pino de saída dele(determinar o estado lógico).


## Experimento 2 (PIC - Arduino)

[![Experimento 2](./../../image/Semana2/PIC-Arduino/PIC-Arduino_GIF.gif)](./../../image/Semana2/PIC-Arduino/PIC-Arduino.jpg)

Nesse experimento, o PIC deve ser programado como transmissor e o Arduino como receptor dos dados:

- **Transmissão:** 
O PIC irá ser configurado como transmissor(pino RC6, TX) e o pino RB0 como entrada conectado a um botão com configuração [PULL-UP](https://www.filipeflop.com/blog/entendendo-o-pull-up-e-pull-down-no-arduino/). Quando o botão estiver pressionado, o pino RB0 irá receber LOW(nível lógico baixo) e irá mandar um código para o Arduino, caso contrário ele irá mandar outro código.

- **Recepção:**
O Arduino irá ser configurado como receptor(pino 17, RX2) no setup e irá verificar no loop se recebeu algum dado e dependendo do valor recebido ele irá ativar ou desativar seu LED interno(conectado ao pino 13). Se o botão estiver pressionado, o LED estará desligado, caso contrário ele estará ligado.

- **Resumo:** 
O PIC irá verificar o estado do pino de entrada(se o botão está pressionado ou não) e de acordo com isso irá definir um valor que será transmitido para o Arduino e irá ativar ou desativar um pino dele(determinar o estado lógico).