/**********************************************************
 *              Auto Light Control System                 *
 *               Microcontroller: PIC16F877A              *
 *              Author: Team                              *
 *              Supervisor: Dr. Shereen                   *
 **********************************************************/

//==================== LCD Pin Definitions ====================
sbit LCD_RS at RC2_bit;      // LCD Register Select
sbit LCD_EN at RC3_bit;      // LCD Enable

sbit LCD_D4 at RC4_bit;      // LCD Data Pin D4
sbit LCD_D5 at RC5_bit;      // LCD Data Pin D5
sbit LCD_D6 at RC6_bit;      // LCD Data Pin D6
sbit LCD_D7 at RC7_bit;      // LCD Data Pin D7

//==================== LCD Direction Settings ====================
sbit LCD_RS_Direction at TRISC2_bit;
sbit LCD_EN_Direction at TRISC3_bit;
sbit LCD_D4_Direction at TRISC4_bit;
sbit LCD_D5_Direction at TRISC5_bit;
sbit LCD_D6_Direction at TRISC6_bit;
sbit LCD_D7_Direction at TRISC7_bit;

//==================== Global Variables ====================
char txt[16];                // Buffer to hold ADC value as string
unsigned int adc_value;      // ADC reading from LDR sensor

//==================== Main Function ====================
void main() {
    //----------- Initialization -----------
    ADCON1 = 0x80;          // Configure AN0 as analog input
    TRISA = 0xFF;           // PORTA as input (LDR on RA0)
    TRISB = 0x00;           // PORTB as output (LED on RB0)
    TRISC = 0x00;           // PORTC as output (LCD)

    Lcd_Init();             // Initialize LCD
    Lcd_Cmd(_LCD_CURSOR_OFF);  // Turn off LCD cursor
    Lcd_Cmd(_LCD_CLEAR);       // Clear screen

    //----------- Welcome Message -----------
    Lcd_Out(1, 3, "Welcome :)");
    Lcd_Out(2, 2, "DR:Shereen");
    Delay_ms(1000);
    Lcd_Cmd(_LCD_CLEAR);

    //----------- Project Title -----------
    Lcd_Out(1, 1, "Auto Light");
    Lcd_Out(2, 2, "Control System");
    Delay_ms(1000);
    Lcd_Cmd(_LCD_CLEAR);

    //----------- Project Description -----------
    Lcd_Out(1, 1, "If it's dark,");
    Lcd_Out(2, 1, "light will turn ON");
    Delay_ms(1000);
    Lcd_Cmd(_LCD_CLEAR);

    Lcd_Out(1, 1, "If it's bright,");
    Lcd_Out(2, 1, "light will turn OFF");
    Delay_ms(1000);
    Lcd_Cmd(_LCD_CLEAR);
    Delay_ms(500);

    //==================== Main Loop ====================
    while(1) {
        //----------- Read ADC Value from LDR -----------
        adc_value = ADC_Read(0);     // Read analog value from AN0 (LDR)
                 //----------- Display Light Level -----------
        IntToStr(adc_value, txt);    // Convert ADC value to string
        Lcd_Out(2, 1, "Light:");
        Lcd_Out(2, 8, txt);
        Delay_ms(500);               // Wait before next update         // Show ADC value on LCD
        //----------- Display Light Status -----------
        Lcd_Cmd(_LCD_CLEAR);
        Delay_ms(10);

        if(adc_value < 500) {
            Lcd_Out(1, 3, "Room is DARK");
            PORTB.F0 = 1;            // Turn ON LED
        }
        else {
            Lcd_Out(1, 2, "Room is BRIGHT");
            PORTB.F0 = 0;            // Turn OFF LED
        }




    }
}