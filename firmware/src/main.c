#include "cv01-ili9341v.h"
#include "lvgl.h"
#include "lv_conf.h"

extern lv_font_t pixelon_16;

static void disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map);
void display_task(void *pvParameter);

void app_main() {
    // Initialize the ILI9341V display driver
    ILI9341V_init();

    ILI9341V_fillScreen(0, 0, 0);

    // Create a FreeRTOS task for LVGL display handling
    xTaskCreatePinnedToCore(display_task, "display_task", 4096 * 4, NULL, 5, NULL, 1);
}

void display_task(void *pvParameter) {
    
    //LVGL initializationku miku ooeeoo");
    lv_init();
    lv_display_t* display = lv_display_create(240, 320);
    lv_display_set_rotation(display, LV_DISPLAY_ROTATION_90);
    
    static uint8_t display_buf[320*240 / 10 * 2];
    lv_display_set_buffers(display, display_buf, NULL, sizeof(display_buf), LV_DISPLAY_RENDER_MODE_PARTIAL);

    lv_display_set_flush_cb(display, disp_flush);
    
    lv_style_t style;
    lv_style_init(&style);
    lv_style_set_text_font(&style, &pixelon_16);
    lv_style_set_text_color(&style, lv_color_hex(0x00FFFF));
    lv_style_set_bg_color(&style, lv_color_hex(0x000000));
    lv_style_set_bg_opa(&style, LV_OPA_COVER);

    lv_obj_add_style(lv_scr_act(), &style, 0);

    lv_obj_t * label = lv_label_create(lv_screen_active());
    lv_label_set_text(label, "i think im restarted miku ooeeoo");
    

    while (1) {
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

void disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) {

    uint16_t* px = (uint16_t*)px_map;

    ILI9341V_write(area->x1, area->y1, area->x2, area->y2, px);

    lv_display_flush_ready(disp);
}