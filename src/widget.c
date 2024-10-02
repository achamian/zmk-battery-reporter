#include <zephyr/kernel.h>
#include <zmk/battery.h>
#include <zmk/hid.h>
#include <zmk/keys.h>

#include "zmk_battery_reporter/widget.h"

void report_battery(void) {
    int batt_level = zmk_battery_state_of_charge(); // Get battery percentage
    char batt_str[4]; // Assuming 3 digits + null terminator
    snprintf(batt_str, sizeof(batt_str), "%d%%", batt_level); // Convert to string

    for (int i = 0; batt_str[i] != '\0'; i++) {
        zmk_keycode_tap(batt_str[i]);
    }
}
