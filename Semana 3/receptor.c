// PIC18F45K20

#include <xc.h>

#pragma config FOSC = RCIO6     // Oscillator Selection bits (External RC oscillator, port function on RA6)
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled) 
#pragma config WDTEN = OFF      // Watchdog Timer Enable bit (WDT is controlled by SWDTEN bit of the WDTCON register) 

#define _XTAL_FREQ 1000000

unsigned char valor;

void configura_serial()
{   
    SPBRG = 12; // Baud rate = 1200 bps; Fosc = 1MHz
    
    //Configura RX para 8N1
    RCSTA = 0b10010000;
    TXSTA = 0x00;
}

void main (void)
{
    configura_serial();
    
    // Configura RC7/RX como entrada
    TRISC |= 0b10000000;
    // Configura RD0,RD1,RD2,RD3 como sa?da
    TRISD &= 0b11110000;

    while(1){
        while (PIR1bits.RCIF ==0){};

        valor = RCREG;
        
        if (valor == 0b01010101) {
            PORTD = 0b00001111;
            __delay_ms(300);
        }
        
        PORTD = 0b00000000;
    }
}
