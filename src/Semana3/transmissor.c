// PIC18F45K20

#include <xc.h>

#pragma config FOSC = RCIO6     // Oscillator Selection bits (External RC oscillator, port function on RA6)
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled) 
#pragma config WDTEN = OFF      // Watchdog Timer Enable bit (WDT is controlled by SWDTEN bit of the WDTCON register) 
#pragma config PBADEN = OFF 

#define _XTAL_FREQ 1000000

void configura_serial()
{
    //Configura oscilador interno para 16MHz
    OSCCONbits.IRCF = 0b111;
    
    SPBRG = 12; // Baud rate = 1200 bps; Fosc = 1MHz
    
    //Configura RX e TX para 8N1
    RCSTA = 0b10010000;
    TXSTA = 0b00100000;
}

void main (void)
{
    configura_serial();
    
    //Habilitar as interrup��es
    INTCONbits.PEIE = 1; // Habilita interrup��es perifericas
    INTCONbits.GIE = 1; // Habilita interrup��o geral
    
    // Configura RC6/TX como sa?da
    TRISC &= 0b10111111;
    
    // Configura RB0 como entrada (Bot�o)
    TRISB |= 0b00000001;
    
    while(1){
        PORTDbits.RD0 = 1;
        
        if (PORTBbits.RB0 == 1){
            for (int i = 0; i < 10; i++) {
                TXREG = 0b01010101;

                // Espera concluir a transmiss�o do byte
                while (!(PIR1 & 0b00010000)){};
                __delay_ms(500);
            }
        }
                
    }
}