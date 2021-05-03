///////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------//
//----------H----H--X----X-----CCCCC-----22222----0000-----0000-----11-------//
//---------H----H----X-X-----C--------------2---0----0---0----0---1-1--------//
//--------HHHHHH-----X------C----------22222---0----0---0----0-----1---------//
//-------H----H----X--X----C----------2-------0----0---0----0-----1----------//
//------H----H---X-----X---CCCCC-----22222----0000-----0000----11111---------//
//---------------------------------------------------------------------------//
//----- Contact: hxc2001 at hxc2001.com ----------- https://hxc2001.com -----//
//----- (c) 2021 Jean-Fran�ois DEL NERO ----------- http://hxc2001.free.fr --//
///////////////////////////////////////////////////////////////////////////////

                        Generic STM32 HxCMOD player
                          With SPI Delta Sigma DAC

This folder contains a HxC Mod player firmware for STM32F1xx MCU series.
The firmware implement a delta sigma DAC through the SPI "MOSI" output.
No internal or external DAC controller is needed. You just need to connecta RC
circuit to filter the MOSI and connect it to a an headphone or an amplifier.

The SPI controller to use and the delta sigma / SPI frequency can be changed
in the buildconf.h file. (CONFIG_SPI_PORT and CONFIG_SPI_CLK_DIV)

At the end of the build process the .bin firmware file and the mod file
to play are concatened together. You can add mods files into the "mods"
folder. (each mod file will generate a separated firmware).

Notes:
The current code only use the internal oscillator and run the STM
at 64MHz. Basically you just need to power the MCU to run this firmware.
Regarding the GPIO only the selected SPI MOSI pin is set as output,
all the others pins stay in reset state. You should be able to run
it on many STM32 without modification.

Pre-built firmwares for SPI1 and SPI2 can be found in the prebuilt_test_fw
folder.

Currently successfully tested MCUs:

- STM32F103CBT6
- STM32F105RBT6
- ARTERY AT32F415CBT7
- ARTERY AT32F415RCT7

Should work on many others STM32/AT32 MCUs "out the box"/without
modification as well. The current build just require 16KB of RAM.
Regarding the Flash, the firmware use ~12KB plus the mod file size.

Demonstration video :

<<Software one-bit delta-sigma DAC converter implemented on STM32 MCU >>

Youtube : https://www.youtube.com/watch?v=AQ--IiXPUGA

Jean-Fran�ois DEL NERO (Jeff) / HxC2001

Email : jeanfrancoisdelnero <> free.fr

http://hxc2001.free.fr

30 April 2021
