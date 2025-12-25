#include "cv01-ili9341v.h"
#include <string.h>
#include <math.h>

static spi_device_handle_t spi;

uint16_t buf[1024];
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
    return (b5 << 11) | (g6 << 5) | r5;
}

// Initialize SPI and GPIO pins
void ILI9341V_init(void) {
    // GPIO setup
    gpio_set_direction(LCD_PIN_DC, GPIO_MODE_OUTPUT);
    gpio_set_direction(LCD_PIN_CS, GPIO_MODE_OUTPUT);
    gpio_set_direction(LCD_PIN_BL, GPIO_MODE_OUTPUT);
    gpio_set_level(LCD_PIN_BL, 1); // backlight on
    // Optional: reset pin
    // gpio_set_direction(LCD_PIN_RST, GPIO_MODE_OUTPUT);

    // SPI bus config
    spi_bus_config_t bus_config = {
        .miso_io_num = LCD_PIN_MISO,
        .mosi_io_num = LCD_PIN_MOSI,
        .sclk_io_num = LCD_PIN_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 240 * 320 * 2 
    };
    esp_err_t ret = spi_bus_initialize(HSPI_HOST, &bus_config, SPI_DMA_CH_AUTO);
    if (ret != ESP_OK) { /* handle error */ }

    // SPI device config
    spi_device_interface_config_t dev_config = {
        .clock_speed_hz = 20 * 1000 * 1000, // 10 MHz
        .mode = 0,
        .spics_io_num = LCD_PIN_CS,
        .queue_size = 2,
        .flags = SPI_DEVICE_NO_DUMMY
    };
    ret = spi_bus_add_device(HSPI_HOST, &dev_config, &spi);
    if (ret != ESP_OK) { /* handle error */ }

    vTaskDelay(pdMS_TO_TICKS(100));

    ILI9341V_sendCommand(0x01); // Software reset
    vTaskDelay(pdMS_TO_TICKS(150));

    ILI9341V_sendCommand(0x11); // Sleep out
    vTaskDelay(pdMS_TO_TICKS(150));

    ILI9341V_sendCommand(0x3A); // Pixel format
    ILI9341V_sendData(0x55);    // 16-bit (RGB565)

    ILI9341V_sendCommand(0x36); // MADCTL
    ILI9341V_sendData(0xA0);    // Row/column order (common default)

    ILI9341V_sendCommand(0x29); // Display ON
    vTaskDelay(pdMS_TO_TICKS(50));

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

void ILI9341V_write(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t* color_buff){

    ILI9341V_sendCommand(0x2A);
    ILI9341V_sendData(x1>>8 & 0xFF);
    ILI9341V_sendData(x1 & 0xFF);
    ILI9341V_sendData(x2>>8 & 0xFF);
    ILI9341V_sendData(x2 & 0xFF);

    ILI9341V_sendCommand(0x2B);
    ILI9341V_sendData(y1>>8 & 0xFF);
    ILI9341V_sendData(y1 & 0xFF);
    ILI9341V_sendData(y2>>8 & 0xFF);
    ILI9341V_sendData(y2 & 0xFF);
    
    ILI9341V_sendCommand(0x2C);
    for(int i = 0; i < (x2 - x1 + 1) * (y2 - y1 + 1); i++){
        uint16_t color = color_buff[i];
        ILI9341V_sendData((uint8_t)(color >> 8));  
        ILI9341V_sendData((uint8_t)(color & 0xFF)); 
    } 

}

void ILI9341V_fillScreen(uint8_t r, uint8_t g, uint8_t b) {

    uint16_t *dma_buff = heap_caps_malloc(
        CHUNK_SIZE * sizeof(uint16_t),
        MALLOC_CAP_DMA
    );

    uint16_t color = ILI9341V_rgbto565(r, g, b);
    color = (color >> 8) | (color << 8); //Man i hate endianness

    for(int i = 0; i < CHUNK_SIZE; i++){
        dma_buff[i] = color;
    }
    
    ILI9341V_sendCommand(0x2A);
    ILI9341V_sendData(0x00);
    ILI9341V_sendData(0x00);
    ILI9341V_sendData(0x00);
    ILI9341V_sendData(LCD_WIDTH_LSB);

    ILI9341V_sendCommand(0x2B);
    ILI9341V_sendData(0x00);
    ILI9341V_sendData(0x00);
    ILI9341V_sendData(LCD_HEIGHT_MSB);
    ILI9341V_sendData(LCD_HEIGHT_LSB);

    ILI9341V_sendCommand(0x2C);
    int pix_count = (LCD_WIDTH_LSB + 1) * ((LCD_HEIGHT_MSB << 8) | (LCD_HEIGHT_LSB + 1));
    while(pix_count > 0){
        int send = pix_count > CHUNK_SIZE ? CHUNK_SIZE : pix_count;
        
        spi_transaction_t t;
        memset(&t, 0, sizeof(t));
        t.length = send * 16;
        t.tx_buffer = (const void *)dma_buff;
        gpio_set_level(LCD_PIN_DC, 1);         // DATA mode
        spi_device_transmit(spi, &t);
        pix_count -= send;

    }

    heap_caps_free(dma_buff);
}



// Test: draw a red square
void ILI9341V_test(void) {
    float h = 0.0f;
    float s = 1.0f;
    float v = 1.0f;
    while(1){
        uint8_t r, g, b;

        float c = v * s;
        float x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
        float m = v - c;
        float rp, gp, bp;

        if(h < 60)      { rp = c; gp = x; bp = 0; }
        else if(h < 120){ rp = x; gp = c; bp = 0; }
        else if(h < 180){ rp = 0; gp = c; bp = x; }
        else if(h < 240){ rp = 0; gp = x; bp = c; }
        else if(h < 300){ rp = x; gp = 0; bp = c; }
        else            { rp = c; gp = 0; bp = x; }


        r = (uint8_t)((rp + m) * 255);
        g = (uint8_t)((gp + m) * 255);
        b = (uint8_t)((bp + m) * 255);

        ILI9341V_fillScreen(r, g, b); 

        h += 1.0f;                   
        if(h >= 360.0f) h -= 360.0f;
    }
}
