#include "cv01-ili9341v.h"

void app_main() {
    // Initialize the ILI9341V display
    ILI9341V_init();
    // Main application loop
    while (1) {
        ILI9341V_test();
    }
}