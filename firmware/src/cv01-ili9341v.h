#ifndef CV01_ILI9341V_H
#define CV01_ILI9341V_H

#include "driver/gpio.h"
#include "driver/spi_master.h"
#include <stdint.h>  // for uint8_t, uint16_t

// Pin definitions (can override before including this header)
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

#define LCD_WIDTH_LSB 0xEF
#define LCD_HEIGHT_MSB 0x01
#define LCD_HEIGHT_LSB 0x3F
#define CHUNK_SIZE 4096
#define LCD_WIDTH 240
#define LCD_HEIGHT 320

void ILI9341V_init(void);
void ILI9341V_sendCommand(uint8_t cmd);
void ILI9341V_sendData(uint8_t data);
void ILI9341V_writePixel(uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b);
void ILI9341V_write(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t* color_buff);
uint16_t ILI9341V_rgbto565(uint8_t r, uint8_t g, uint8_t b);
void ILI9341V_test(void);
void ILI9341V_fillScreen(uint8_t r, uint8_t g, uint8_t b);

#endif // CV01_ILI9341V_H
