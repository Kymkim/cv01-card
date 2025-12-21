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

// Initialize SPI bus and GPIOs
void ILI9341V_init(void);

// Send a single command byte
void ILI9341V_sendCommand(uint8_t cmd);

// Send a single data byte
void ILI9341V_sendData(uint8_t data);

// Draw a single pixel at (x,y) with 8-bit RGB values
void ILI9341V_writePixel(uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b);

// Convert 8-bit RGB to 16-bit RGB565
uint16_t ILI9341V_rgbto565(uint8_t r, uint8_t g, uint8_t b);

// Draw test pattern (e.g., red square)
void ILI9341V_test(void);

// Optional: clear the screen with a color (you can implement in C file)
void ILI9341V_clear(uint16_t color);

#endif // CV01_ILI9341V_H
