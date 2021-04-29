#ifndef CONFIG_FILE_INCLUDED
#define CONFIG_FILE_INCLUDED 1

#define PAST2(x,y) x ## y
#define EVAL2(x,y)  PAST2(x,y)

#define PAST3(x,y,z) x ## y ## z
#define EVAL3(x,y,z)  PAST3(x,y,z)

#define PAST4(a,b,c,d) a ## b ## c ## d
#define EVAL4(a,b,c,d)  PAST4(a,b,c,d)

#define PAST5(a,b,c,d,e) a ## b ## c ## d ## e
#define EVAL5(a,b,c,d,e) PAST5(a,b,c,d,e)

#define SYSTICK_IRQ_PRIORITY 12

#define CONFIG_SPI_PORT 2

#if CONFIG_SPI_PORT == 2
  #define CONFIG_DMA_CHANNEL 5
  #define CONFIG_DMA_PORT 1
  #define DMA_
#else
  #define CONFIG_DMA_CHANNEL 3
  #define CONFIG_DMA_PORT 1
#endif

#define CONFIG_SPI_CTRL         EVAL2(SPI, CONFIG_SPI_PORT)
#define CONFIG_DMA_CTRL         EVAL2(DMA, CONFIG_DMA_PORT)
#define CONFIG_DMA_CHN_CTRL     EVAL4(DMA, CONFIG_DMA_PORT, _Channel, CONFIG_DMA_CHANNEL)
#define CONFIG_DMA_CHN_CTRL_IRQ EVAL5(DMA, CONFIG_DMA_PORT, _Channel, CONFIG_DMA_CHANNEL, _IRQn)
#define DMA_IRQ_ENTRY_NAME      EVAL5(DMA, CONFIG_DMA_PORT, _Channel, CONFIG_DMA_CHANNEL, _IRQHandler)

// SPI Clock Divisor
// 0 -> /2  (32Mhz / 2 -> 16MHz delta sigma DAC)
// 1 -> /4  (32Mhz / 4 ->  8MHz delta sigma DAC)
// 2 -> /8  (32Mhz / 8 ->  4MHz delta sigma DAC)
// 3 -> /16 (32Mhz / 16 -> 2MHz delta sigma DAC)
// 4 -> /32 (32Mhz / 32 -> 1MHz delta sigma DAC)

#define CONFIG_SPI_CLK_DIV 1

#define CONFIG_DELTASIGMA_BITS_PER_SAMPLE 256

#define CONFIG_SAMPLE_RATE ((32000000 / (2<<CONFIG_SPI_CLK_DIV) ) / (CONFIG_DELTASIGMA_BITS_PER_SAMPLE))

#include "custom_buildconf.h"

#endif