# Parametric Speaker
Ultrasonic sound has much smaller wavelengths than regular audible sound making it much more directional than a traditional loudspeaker system.

The inteference of the 91 ultrasonic trancducers creates a directed speaker effect with a very narrow FOV ob -30dB @ ~ 2-3 degree.

For more background information about the physics behind this: https://en.wikipedia.org/wiki/Sound_from_ultrasound

## Hardware

Basically the speaker consists of a varible DC/DC converter and a MOSFET fullbridge. The DC/DC creates a variable bridge voltage, while the H bridge creates the actual 40kHz carrier signal.

For now, all the 91 Ultrasonic transducers are in parallel. In the future i plan to build an actual phased array, so stay tuned.

## Software

So far, the firmware on the STM32 doesn't do very much. It's required to initialize all the components via I2C. It also controls a small I2C OLED display and reads some buttons for adjusting volume, frequency, etc.

It' written using mbed so far, unfortuantly this is very inefficient. I'll probably use libopencm3 in the future.
