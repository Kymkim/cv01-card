#include "cv01-ili9341v.h"
#include "lvgl.h"
#include "lv_conf.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_http_client.h"
#include "esp_timer.h"

#include "secret.h"


#define BUFF_SIZE (320*240 / 10)
extern lv_font_t pixelon_16;

static void disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map);
static void ui_components();
static void update_stats_cb(lv_timer_t* timer);
void wifi_init();
void display_task(void *pvParameter);
void lv_tick_cb(void* arg) {
    lv_tick_inc(5); // Increment LVGL tick by 5 milliseconds
}

int player_rating = 0;
char wifi_status[32] = "Disconnected";

void app_main() {
    // Initialize the ILI9341V display driver
    ILI9341V_init();
    ILI9341V_fillScreen(0, 0, 0);

    nvs_flash_init();
    wifi_init();

    // Create a FreeRTOS task for LVGL display handling
    xTaskCreatePinnedToCore(display_task, "display_task", 4096 * 4, NULL, 5, NULL, 1);
}

void wifi_init(){
    esp_netif_init();
    esp_event_loop_create_default();
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);

    wifi_config_t wifi_config = {
        .sta = {
            .ssid = WIFI_SSID,
            .password = WIFI_PASSWORD,
        },
    };
    esp_wifi_set_config(WIFI_IF_STA, &wifi_config);
    esp_wifi_start();

    esp_wifi_connect();
}

void display_task(void *pvParameter) {
    
    //Initialize LVGL
    lv_init();
    lv_display_t* display = lv_display_create(240, 320);
    lv_display_set_rotation(display, LV_DISPLAY_ROTATION_90);
    
    //Allocate LGVL display buffers
    lv_color_t * buf1 = heap_caps_malloc(BUFF_SIZE *sizeof(lv_color_t), MALLOC_CAP_DMA);
    lv_color_t * buf2 = heap_caps_malloc(BUFF_SIZE *sizeof(lv_color_t), MALLOC_CAP_DMA);
    lv_display_set_buffers(display, buf1, buf2, BUFF_SIZE, LV_DISPLAY_RENDER_MODE_PARTIAL);

    //Set Flush Callback
    lv_display_set_flush_cb(display, disp_flush);

    //Set basic style
    lv_style_t style;
    lv_style_init(&style);
    lv_style_set_text_font(&style, &pixelon_16);
    lv_style_set_text_color(&style, lv_color_hex(0x00FFFF));
    lv_style_set_bg_color(&style, lv_color_hex(0x000000));
    lv_style_set_bg_opa(&style, LV_OPA_COVER);
    lv_obj_add_style(lv_scr_act(), &style, 0);

    ui_components();

// Create a task tick source for LVGL (important!)
    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &lv_tick_cb,
        .name = "LVGL tick"
    };
    esp_timer_handle_t periodic_timer;
    esp_timer_create(&periodic_timer_args, &periodic_timer);
    esp_timer_start_periodic(periodic_timer, 5000); // 5ms tick
    
    while (1) {
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

static void ui_components() {
    // Create UI components here
    lv_obj_t * label = lv_label_create(lv_scr_act());
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(label, "Rating: 0");

    lv_timer_create(update_stats_cb, 500, label);
}

static void update_stats_cb(lv_timer_t* timer) {
    // Update player stats
    player_rating += 1;

    char buf[32];
    snprintf(buf, sizeof(buf), "Rating: %d", player_rating);

    // Get the label from timer user_data
    lv_obj_t * label = lv_timer_get_user_data(timer);  

    // Update label
    lv_label_set_text(label, buf);
}




void disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) {

    uint16_t* px = (uint16_t*)px_map;

    ILI9341V_write(area->x1, area->y1, area->x2, area->y2, px);

    lv_display_flush_ready(disp);
}