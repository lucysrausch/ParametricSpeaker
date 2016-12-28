/******************************************************************//**
* @file max5387.h
* Copyright (C) 2015 Maxim Integrated Products, Inc., All Rights Reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
* OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*
* Except as contained in this notice, the name of Maxim Integrated
* Products, Inc. shall not be used except as stated in the Maxim Integrated
* Products, Inc. Branding Policy.
*
* The mere transfer of this software does not imply any licenses
* of trade secrets, proprietary technology, copyrights, patents,
* trademarks, maskwork rights, or any other form of intellectual
* property whatsoever. Maxim Integrated Products, Inc. retains all
* ownership rights.
**********************************************************************/


#ifndef MAX5387_H
#define MAX5387_H

#include "mbed.h"


/**
* @brief Dual, 256-Tap, Volatile, Low-Voltage Linear Taper Digital 
* Potentiometer
*
* @details The MAX5387 dual, 256-tap, volatile, low-voltage linear 
* taper digital potentiometer offers three end-to-end resistance values
* of 10kΩ, 50kΩ, and 100kΩ. Operating from a single +2.6V to +5.5V power
* supply, the device provides a low 35ppm/°C end-to-end temperature 
* coefficient. The device features an I2C interface.
*
* @code 
* #include "mbed.h"
* #include "max5387.h"
* 
* int main (void)
* {
*      Max5387 digiPot(D14, D15, Max5387::MAX5387_I2C_ADRS0);
*      uint8_t data;
*      
*      //set data...
*
*      digiPot.write_ch_A(data);
*      
*      //... rest of application
* }
* @endcode
*/
class Max5387
{
    public:
    
    /**
    * @brief Valid 7-bit I2C addresses 
    * @details The 8 valid I2C addresses set via A0, A1, and A2 pins
    * of the MAX5387
    */ 
    typedef enum
    {
        MAX5387_I2C_ADRS0 = 0x28,
        MAX5387_I2C_ADRS1,
        MAX5387_I2C_ADRS2,
        MAX5387_I2C_ADRS3,
        MAX5387_I2C_ADRS4,
        MAX5387_I2C_ADRS5,
        MAX5387_I2C_ADRS6,
        MAX5387_I2C_ADRS7
    }max5387_i2c_adrs_t;
    
    
    /**********************************************************//**
    * @brief Constructor for Max5387 Class.  
    * 
    * @details Allows user to use existing I2C object
    *
    * On Entry:
    *     @param[in] i2c_bus - pointer to existing I2C object
    *     @param[in] i2c_adrs - 7-bit slave address of MAX5387
    *
    * On Exit:
    *
    * @return None
    **************************************************************/
    Max5387(I2C *i2c_bus, max5387_i2c_adrs_t i2c_adrs);
    
    
    /**********************************************************//**
    * @brief Constructor for Max5387 Class.  
    * 
    * @details Allows user to create a new I2C object if not 
    *          already using one
    *
    * On Entry:
    *     @param[in] sda - sda pin of I2C bus
    *     @param[in] scl - scl pin of I2C bus
    *     @param[in] i2c_adrs - 7-bit slave address of MAX5387
    *
    * On Exit:
    *
    * @return None
    **************************************************************/
    Max5387(PinName sda, PinName scl, max5387_i2c_adrs_t i2c_adrs);
    
    
    /**********************************************************//**
    * @brief Default destructor for Max5387 Class.  
    *
    * @details Destroys I2C object if owner 
    *
    * On Entry:
    *
    * On Exit:
    *
    * @return None
    **************************************************************/
    ~Max5387();
    
    
    /**********************************************************//**
    * @brief Write channel A
    *
    * @details    
    *
    * On Entry:
    *    @param[in] val - wiper position of channel A
    *
    * On Exit:
    *
    * @return 0 on success, non-0 on failure
    **************************************************************/
    int16_t write_ch_A(uint8_t val);
    
    
    /**********************************************************//**
    * @brief Write channel B
    *
    * @details    
    *
    * On Entry:
    *    @param[in] val - wiper position of channel B
    *
    * On Exit:
    *
    * @return 0 on success, non-0 on failure
    **************************************************************/
    int16_t write_ch_B(uint8_t val);
    
    
    /**********************************************************//**
    * @brief Write channel A&B
    *
    * @details    
    *
    * On Entry:
    *    @param[in] val - wiper position of channel A&B
    *
    * On Exit:
    *
    * @return 0 on success, non-0 on failure
    **************************************************************/
    int16_t write_ch_AB(uint8_t val);
    
    
    private:
    
    I2C *_p_i2c;
    bool _i2c_owner;
    uint8_t _w_adrs;
};

#endif/* MAX5387_H */