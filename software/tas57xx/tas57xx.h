#include "mbed.h"

// default values for inputmux
uint8_t buffer_inputmux[4] = {0x00, 0b00000110, 0b01110111, 0b01110010};

// default values for outputmux
uint8_t buffer_outputmux[4] = {0x01, 0b00000000, 0b00000000, 0b01000101};

class tas57xx {
public:
  tas57xx(I2C* i2cinst_){
    i2cinst = i2cinst_;
  }

  // initialization
  void init(){

    // start PLL
    write8(0x1B, 0x00);
    wait_ms(120);

    // set volume
    write8(0x07, 0x04);
    wait_ms(10);

    // input mux
    write32(0x20, buffer_inputmux);
    wait_ms(20);

    // output mux
    write32(0x25, buffer_outputmux);
    wait_ms(10);

    // enable driver
    write8(0x05, 0x00);
    wait_ms(10);
    write8(0x06, 0x00);
    wait_ms(10);
    write8(0x02, 0x00);
    wait_ms(50);
  }

private:

  // default i2c address
  const uint8_t i2caddr = 0x2A;

  // write single byte
  void write8 (uint8_t reg, uint8_t value){
    char buffer[2];
    buffer[0] = reg;
    buffer[1] = value;
    i2cinst->write(i2caddr << 1, buffer, 2);
  }

  // write 4 bytes
  void write32 (uint8_t reg, uint8_t *value){
    char buffer[4 + 1];
    buffer[0] = reg;
    for(uint8_t i=0; i<4; i++){
      buffer[1+i] = value[i];
    }
    i2cinst->write(i2caddr << 1, buffer, 5);
  }

  // store I2C instance
  I2C* i2cinst;
};
