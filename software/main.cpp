

#include "mbed.h"
//#include "Adafruit_SSD1306.h"
#include "Adafruit_SI5351.h"
#include "max5387.h"
#include "tas57xx.h"

DigitalOut inSelect(PA_3);

class I2CPreInit : public I2C
{
public:
    I2CPreInit(PinName sda, PinName scl) : I2C(sda, scl)
    {
        frequency(400000);
        start();
    };
};


I2CPreInit gI2C(PB_7,PB_6);
//Adafruit_SSD1306_I2c gOled2(gI2C,PA_15);

Max5387 digiPot(&gI2C, Max5387::MAX5387_I2C_ADRS0);

Adafruit_SI5351 clockgen = Adafruit_SI5351(&gI2C);

tas57xx classd(&gI2C);

int main()
{   uint16_t x=0;

    //gOled2.printf("%ux%u OLED Display\r\n", gOled2.width(), gOled2.height());

    inSelect = true;

    clockgen.begin();
    //clockgen.setupPLL(SI5351_PLL_A, 26, 1694, 3125);
  clockgen.setupPLL(SI5351_PLL_A, 26, 1694, 3125);
  //clockgen.setupMultisynthInt(2, SI5351_PLL_A, 487);
  //clockgen.setupMultisynthInt(2, SI5351_PLL_A, SI5351_MULTISYNTH_DIV_512);
  clockgen.setupMultisynth(2, SI5351_PLL_A, 512, 0, 1);
  clockgen.setupRdiv(2, SI5351_R_DIV_32);

  clockgen.setupPLL(SI5351_PLL_B, 27, 1641, 3125);
  clockgen.setupMultisynth(0, SI5351_PLL_B, 56, 0, 1);
  clockgen.setupRdiv(0, SI5351_R_DIV_1);

  clockgen.enableOutputs(true);

  digiPot.write_ch_AB(20);

  wait(1);

  // init TAS
  classd.init();

  //clockgen.setupPLLInt(SI5351_PLL_B, 15);
  //clockgen.setupMultisynthInt(0, SI5351_PLL_B, SI5351_MULTISYNTH_DIV_8);
  //clockgen.setupRdiv(0, SI5351_R_DIV_4);
/*
    while(1)
    {
        gOled2.printf("%u\r",x);
        gOled2.display();
        x++;
        wait(1.0);
    }*/
}
