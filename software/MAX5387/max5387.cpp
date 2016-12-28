/******************************************************************//**
* @file max5387.cpp
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


#include "max5387.h"


#define MAX5387_CMD_A  (0x11)
#define MAX5387_CMD_B  (0x12)
#define MAX5387_CMD_AB (0x13)


//*********************************************************************
Max5387::Max5387(I2C *i2c_bus, max5387_i2c_adrs_t i2c_adrs): _p_i2c(i2c_bus)
{
    _i2c_owner = false;

    _w_adrs = (i2c_adrs << 1);
}


//*********************************************************************
Max5387::Max5387(PinName sda, PinName scl, max5387_i2c_adrs_t i2c_adrs)
{
    _p_i2c = new I2C(sda, scl);
    _i2c_owner = true;

    _w_adrs = (i2c_adrs << 1);
}


//*********************************************************************
Max5387::~Max5387()
{
    if(_i2c_owner)
    {
        delete _p_i2c;
    }
}


//*********************************************************************
int16_t Max5387::write_ch_A(uint8_t val)
{
    char data[] = {MAX5387_CMD_A, val};

    return(_p_i2c->write(_w_adrs, data, 2, false));
}


//*********************************************************************
int16_t Max5387::write_ch_B(uint8_t val)
{
    char data[] = {MAX5387_CMD_B, val};

    return(_p_i2c->write(_w_adrs, data, 2, false));
}


//*********************************************************************
int16_t Max5387::write_ch_AB(uint8_t val)
{
    char data[] = {MAX5387_CMD_AB, val};

    return(_p_i2c->write(_w_adrs, data, 2, false));
}
