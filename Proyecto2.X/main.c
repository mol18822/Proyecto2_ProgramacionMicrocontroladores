/*
// Dispositivo:		PIC16F887
// Autor;			Luis Pedro Molina Velásquez 
// Carné;			18822
// Compilador:		pic-as (v2.31) MPLABX V5.40
// ----------------------------------------------------------------------------     
// ------------------------- Proyecto No. 2 -----------------------------------      
// ---------------------------- Carrito   -------------------------------------

// Creado:                  11 mayo , 2021
// Ultima modificación:     04 junio, 2021

//  Bits de configuracion   

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 8000000
#include <xc.h>
#include <stdint.h>
#include <stdio.h>

// ----------------------------- Variables ------------------------------------

// ------------------- Configuración de interrupciones ------------------------

void setup(void);                       //
void chanel(void);                      //
void 

// ------------------------------ Main ----------------------------------------

void main(void) {                       //
    setup();                            //

//------------------------------- Loop ----------------------------------------

    while(1) {                          //
        text();                         //
    }
}    

// ------------------------------ Putch --------------------------------------- 

void putch(char data) {                 // Función de libreria stdio.h
    
    while (TXIF == 0);                  // 
    TXREG = data;                       //
    return;
}

// ------------------------------- Text ---------------------------------------

void text(void) {
    
    __delay_ms(250);                    //
    printf(" ¿Qué acción desea ejecutar? \r ");
    
    __delay_ms(250);                    //
    printf(" 1. ¿Desea elevar la grúa? \r ");
    
    __delay_ms(250);                    //
    printf(" 2. ¿Desea regresar la grúa a su posición inicial? \r ");
    
    __delay_ms(250);                    //
    printf(" 3. ¿Desea activar el modo ambulancia? \r ");
    
    while (RCIF == 0);                  // Si flag RCIF == 0
    
    if (RCREG == '1') {                 // Si se presionó 1
        __delay_ms(500);                //
        printf(" La grúa se está elevando... \r ");
        while (RCIF == 0);              // Mientras flag RCIF == 0
        // Acá es donde traslado la instrucción de RCREG a PORTx
    }
    
    if (RCREG == '2') {                 // Si se presionó 2
        __delay_ms(500);                //
        printf(" La grúa está regresando a su posición inicial... \r ");
        while (RCIF == 0);              // Mientras flag RCIF == 0
        // Acá es donde traslado la instrucción de RCREG a PORTx
    }
    
    if (RCREG == '3') {                 // Si se presionó 3
        __delay_ms(500);                //
        printf(" El modo ambulancia está activado... \r ");
        while (RCIF == 0);              // Mientras flag RCIF == 0
        // Acá es donde traslado la instrucción de RCREG a PORTx
    }
    
    else {                              // Si se presiona algo distinto
        NULL;                           // No ejecuta nada 
    }
    
    return;
}

// ----------------------- Configuración de I/O -------------------------------

void setup(void) {
    
    ANSEL  = 0x00;                      //
    ANSELH = 0x00;                      //
    
    TRISA = 0x00;                       // PORTA como outputs
    TRISB = 0x00;                       // PORTB como outputs

// ------------------------- Limpieza de puertos ------------------------------
    
    PORTA = 0x00;                       //
    PORTB = 0x00;                       //    

// ------------------------ Configuración de Pull-up -------------------------- 

    
// ------------------ Configuración de oscillador interno ---------------------

    OSCCONbits.IRCF2 = 1;               // 1
    OSCCONbits.IRCF1 = 1;               // 1
    OSCCONbits.IRCF0 = 1;               // 1 --> 8 MHz
    OSCCONbits.SCS   = 1;               // Activando oscillador
    
// ------------------------ Configuración de Timer0 ---------------------------

// -------------------- Configuración de interrupciones -----------------------
    
    INTCONbits.GIE  = 1;                 //
    INTCONbits.PEIE = 1;                 //
    PIE1bits.RCIE   = 1;                 // RX
    PIE1bits.TXIE   = 1;                 // TX    

// ----------------------- Configuración de módulo ADC ------------------------

// ----------------------- Configuración de módulo PWM ------------------------

// ----------------- Configuración de comunicación serial ---------------------
    
    TXSTAbits.SYNC    = 0;
    TXSTAbits.BRGH    = 1;
    BAUDCTLbits.BRG16 = 1;
    
    SPBRG = 207;
    SPBRGH = 0;
    
    RCSTAbits.SPEN = 1;
    RCSTAbits.RX9  = 0;
    RCSTAbits.CREN = 1;
    
    TXSTAbits.TXEN = 1;
    
    PIR1bits.RCIF = 0;                  // Bandera rx
    PIR1bits.TXIF = 0;                  // bandera tx  

}
*/

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 4000000
#include <xc.h>
#include <stdint.h>

// ------------------- Configuración de interrupciones ------------------------

void setup(void);
void leds(void);

void __interrupt() isr(void) {

    if(PIR1bits.ADIF == 1) {            // Flag de módulo ADC == 1
        
    if(ADCON0bits.CHS == 0)             // Canal 0 == 1 --> Enviar a PORTC
        CCPR2L = (ADRESH >> 1) + 124;

    else CCPR1L = (ADRESH >> 1) + 124;
         PIR1bits.ADIF = 0;            // Flag de módulo ADC == 0
       }    
    }
// ------------------------------ Main ----------------------------------------

void main(void) {
    
    setup();                            // Llamando configuración
    
//------------------------------- Loop ----------------------------------------
   
    while(1) {                           // 
    leds();
        if(ADCON0bits.GO == 0){         // Switcheo de canal  
        if(ADCON0bits.CHS == 1)         // Si la señal == 1 --> Regresa a 0
           ADCON0bits.CHS = 0;          // 
           
        else ADCON0bits.CHS = 1;        // Si la señal =! 1 --> Regresa a 1
            
        __delay_us(100);                // Delay de 100us
        ADCON0bits.GO = 1;              // Conversiones == 1
        }
    }
}
   

void leds(void) {
    
if (PORTAbits.RA2 == 0){
    __delay_ms(500);
    if (PORTAbits.RA2 == 1){    
    PORTBbits.RB0 = 1; 
    __delay_ms(500);
    for (int x = 0; x <= 30; x++) {
        if (x == 29) {
        PORTBbits.RB0 = 0;
        }
    }
        }
    }

if (PORTAbits.RA3 == 0){
    __delay_ms(500);
    if (PORTAbits.RA3 == 1){    
    PORTBbits.RB1 = 1; 
    __delay_ms(500);
    for (int x = 0; x <= 30; x++) {
        if (x == 29) {
        PORTBbits.RB1 = 0;
        }
    }
        }
    }
}

// ----------------------- Configuración de I/O -------------------------------

void setup(void) {
    
    ANSEL  = 0b00000011;                 //
    ANSELH = 0;                          //
    
    TRISAbits.TRISA0 = 1;                // AN0 --> Input --> Potenciometro 1
    TRISAbits.TRISA1 = 1;                // AN1 --> Input --> Potenciometro 2
    TRISAbits.TRISA2 = 1;                // PB pide viaz izquierdo
    TRISAbits.TRISA3 = 1;                // PB pide viaz derecho
    TRISBbits.TRISB0 = 0;                // Pide viaz izquierdo
    TRISBbits.TRISB1 = 0;                // Pide viaz derecho

// ------------------------- Limpieza de puertos ------------------------------

    PORTA = 0x00;   
    PORTB = 0X00;
    PORTC = 0x00;
    
// ------------------ Configuración de oscillador interno --------------------- 
    
    OSCCONbits.IRCF2 = 1;                // 1
    OSCCONbits.IRCF1 = 1;                // 1
    OSCCONbits.IRCF0 = 1;                // 1 --> 8 MHz
    OSCCONbits.SCS   = 1;                // Oscillador interno == 1

// -------------------- Configuración de interrupciones -----------------------
    
    INTCONbits.GIE  = 1;                  // 
    INTCONbits.PEIE = 1;                  // Periferical interrupt == 1
    PIE1bits.ADIE   = 1;                  // ADC interrupt == 1
    PIR1bits.ADIF   = 0;                  // ADC flag == 0

// ----------------------- Configuración de módulo ADC ------------------------
    
    ADCON0bits.ADCS0 = 0;                 // 
    ADCON0bits.ADCS1 = 1;                 //
    ADCON0bits.ADON  = 1;                 // ADC == 1
    ADCON0bits.CHS   = 0;                 // Canal 0
    __delay_us(50);                       //
    ADCON1bits.ADFM  = 0;                 // Justificación izq
    ADCON1bits.VCFG0 = 0;                 // VSS y VDD --> voltajes de ref
    ADCON1bits.VCFG1 = 0;                 //

// ----------------------- Configuración de módulo PWM ------------------------
    
    TRISCbits.TRISC1   = 1;               //
    TRISCbits.TRISC2   = 1;               //
    PR2 = 250;                            // Periodo
    CCP1CONbits.P1M    = 0;               // Configuración de PWM
    CCP1CONbits.CCP1M  = 0b1100;          // Configuración de PWM1
    CCP2CONbits.CCP2M  = 0b1100;          // Configuración de PWM2
    CCPR1L = 0x0f;                        //
    CCP1CONbits.DC1B   = 0;               //
    PIR1bits.TMR2IF    = 0;               // 
    T2CONbits.T2CKPS   = 0b11;            //
    T2CONbits.TMR2ON   = 1;               //
    
    while(PIR1bits.TMR2IF == 0);
    PIR1bits.TMR2IF = 0;
    
    TRISCbits.TRISC1 = 0;                // Servo 1
    TRISCbits.TRISC2 = 0;                // Servo 2
    
}        