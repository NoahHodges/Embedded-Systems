#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 500 

DigitalOut red(TRAF_RED1_PIN,1);         //Note the initial state
DigitalOut amber(TRAF_YEL1_PIN,0);
DigitalOut green(TRAF_GRN1_PIN,0);

LCD_16X2_DISPLAY lcd;

int main()
{
    while (true)
    {

        lcd.puts("RED");
        wait_us(WAIT_TIME_MS * 20000);

        amber = 1;
        lcd.cls();
        lcd.puts("   AMBER");
        wait_us(WAIT_TIME_MS * 3000);

        red = 0;
        amber = 0;

        green = 1;
        lcd.cls();
        lcd.puts("   GREEN");
        wait_us(WAIT_TIME_MS * 20000);

        green = 0;

        amber = 1;
        lcd.cls();
        lcd.puts("   AMBER");
        wait_us(WAIT_TIME_MS * 2000);

        amber= 0;
        
        red = 1;
        lcd.cls();
        lcd.puts("      ");
        wait_us(WAIT_TIME_MS * 10);
    }
}
