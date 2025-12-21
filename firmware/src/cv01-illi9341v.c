#include "cv01-ili9341v.h"
#include <string.h>

static spi_device_handle_t spi;

// Helper macros for single-byte SPI transactions
void ILI9341V_sendCommand(uint8_t command) { 
    gpio_set_level(LCD_PIN_DC, 0); // command mode
    spi_transaction_t t;
    memset(&t, 0, sizeof(t));
    t.length = 8;               // 8 bits
    t.tx_buffer = &command;
    spi_device_transmit(spi, &t);
}

void ILI9341V_sendData(uint8_t data) { 
    gpio_set_level(LCD_PIN_DC, 1); // data mode
    spi_transaction_t t;
    memset(&t, 0, sizeof(t));
    t.length = 8;                // 8 bits
    t.tx_buffer = &data;
    spi_device_transmit(spi, &t);
}

// RGB888 -> RGB565 conversion (with proper rounding)
uint16_t ILI9341V_rgbto565(uint8_t r, uint8_t g, uint8_t b) { 
    uint16_t r5 = (r * 31 + 127) / 255;  // 0-31
    uint16_t g6 = (g * 63 + 127) / 255;  // 0-63
    uint16_t b5 = (b * 31 + 127) / 255;  // 0-31
    return (r5 << 11) | (g6 << 5) | b5;
}

// Initialize SPI and GPIO pins
void ILI9341V_init(void) {
    // GPIO setup
    gpio_set_direction(LCD_PIN_DC, GPIO_MODE_OUTPUT);
    gpio_set_direction(LCD_PIN_CS, GPIO_MODE_OUTPUT);
    // Optional: reset pin
    // gpio_set_direction(LCD_PIN_RST, GPIO_MODE_OUTPUT);

    // SPI bus config
    spi_bus_config_t bus_config = {
        .miso_io_num = LCD_PIN_MISO,
        .mosi_io_num = LCD_PIN_MOSI,
        .sclk_io_num = LCD_PIN_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1
    };
    esp_err_t ret = spi_bus_initialize(HSPI_HOST, &bus_config, SPI_DMA_CH_AUTO);
    if (ret != ESP_OK) { /* handle error */ }

    // SPI device config
    spi_device_interface_config_t dev_config = {
        .clock_speed_hz = 10 * 1000 * 1000, // 10 MHz
        .mode = 0,
        .spics_io_num = LCD_PIN_CS,
        .queue_size = 7
    };
    ret = spi_bus_add_device(HSPI_HOST, &dev_config, &spi);
    if (ret != ESP_OK) { /* handle error */ }
}

// Write a single pixel at (x,y)
void ILI9341V_writePixel(uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b) { 
    uint16_t color = ILI9341V_rgbto565(r, g, b);

    // Column address
    ILI9341V_sendCommand(0x2A);
    ILI9341V_sendData((x >> 8) & 0xFF);
    ILI9341V_sendData(x & 0xFF);
    ILI9341V_sendData((x >> 8) & 0xFF);
    ILI9341V_sendData(x & 0xFF);

    // Row address
    ILI9341V_sendCommand(0x2B);
    ILI9341V_sendData((y >> 8) & 0xFF);
    ILI9341V_sendData(y & 0xFF);
    ILI9341V_sendData((y >> 8) & 0xFF);
    ILI9341V_sendData(y & 0xFF);

    // Write pixel
    ILI9341V_sendCommand(0x2C);
    ILI9341V_sendData((uint8_t)(color >> 8));  // MSB
    ILI9341V_sendData((uint8_t)(color & 0xFF)); // LSB
}

// Test: draw a red square
void ILI9341V_test(void) {
    for (uint16_t x = 10; x < 50; x++) {
        for (uint16_t y = 10; y < 50; y++) {
            ILI9341V_writePixel(x, y, 0xFF, 0x00, 0x00); // red
        }
    }
}
