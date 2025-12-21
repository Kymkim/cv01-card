#ifndef CV01_ILI9341V_H
#define CV01_ILI9341V_H

#include "driver/gpio.h"
#include "driver/spi_master.h"

#ifndef LCD_PIN_CS
#define LCD_PIN_CS 15
#endif

#ifndef LCD_PIN_DC
#define LCD_PIN_DC 2
#endif

#ifndef LCD_PIN_CLK
#define LCD_PIN_CLK 14
#endif

#ifndef LCD_PIN_MOSI
#define LCD_PIN_MOSI 13
#endif

#ifndef LCD_PIN_MISO
#define LCD_PIN_MISO 12
#endif

#ifndef LCD_PIN_BL
#define LCD_PIN_BL 21
#endif

void ILI9341V_init(void);
void ILI9341V_clear(uint16_t color);
void ILI9341V_drawPixel(uint16_t x, uint16_t y, uint16_t color);
void ILI9341V_sendCommand(uint8_t cmd);
void ILI9341V_sendData(uint8_t* data);

#endif