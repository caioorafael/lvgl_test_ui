

#include "display.h"
#include "ui_helpers.h"
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/display.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(display, LOG_LEVEL_DBG);
///////////////////// VARIABLES ////////////////////
const struct device *display_dev;

// SCREEN: ui_mqttScreen
void ui_mqttScreen_screen_init(void);
lv_obj_t *ui_mqttScreen;
lv_obj_t *ui_mqttTag;
lv_obj_t *ui_mqttStatus;


// SCREEN: ui_lteScreen
void ui_lteScreen_screen_init(void);
lv_obj_t *ui_lteScreen;
lv_obj_t *ui_lteTag;
lv_obj_t *ui_lteStatus;
lv_obj_t *ui____initial_actions0;


///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_mqttScreen_screen_init(void)
{
ui_mqttScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_mqttScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_mqttTag = lv_label_create(ui_mqttScreen);
// lv_obj_set_width( ui_mqttTag, 100);
// lv_obj_set_height( ui_mqttTag, 30);
lv_obj_set_size( ui_mqttTag, 100, 30);
//lv_obj_set_align( ui_mqttTag, LV_ALIGN_TOP_MID );
lv_obj_set_pos( ui_mqttTag, 0, 0);
lv_label_set_text(ui_mqttTag,"mqttStatus:");
//lv_obj_clear_flag( ui_mqttTag, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_mqttTag, LV_SCROLLBAR_MODE_OFF);

ui_mqttStatus = lv_label_create(ui_mqttScreen);
// lv_obj_set_width( ui_mqttStatus, 100);
// lv_obj_set_height( ui_mqttStatus, 30);
lv_obj_set_size( ui_mqttStatus, 100, 30);
//lv_obj_set_align( ui_mqttStatus, LV_ALIGN_BOTTOM_MID );
lv_obj_set_pos( ui_mqttStatus, 0, 45);
lv_label_set_text(ui_mqttStatus,"Unknown");
//lv_obj_clear_flag( ui_mqttStatus, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_mqttStatus, LV_SCROLLBAR_MODE_OFF);

}


void ui_lteScreen_screen_init(void)
{
ui_lteScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_lteScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_lteTag = lv_label_create(ui_lteScreen);

// lv_obj_set_width( ui_lteTag, 100);
// lv_obj_set_height( ui_lteTag, 30);
lv_obj_set_size( ui_lteTag, 100, 30);

//lv_obj_set_align( ui_lteTag, LV_ALIGN_TOP_MID );
lv_obj_set_pos( ui_lteTag, 0, 0);
lv_label_set_text(ui_lteTag,"lteStatus:");
//lv_obj_clear_flag( ui_lteTag, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_lteTag, LV_SCROLLBAR_MODE_OFF);

ui_lteStatus = lv_label_create(ui_lteScreen);

// lv_obj_set_width( ui_lteStatus, 100);
// lv_obj_set_height( ui_lteStatus, 30);
lv_obj_set_size( ui_lteStatus, 100, 30);
// lv_obj_set_align( ui_lteStatus, LV_ALIGN_BOTTOM_MID );
lv_obj_set_pos( ui_lteStatus, 0, 45);
lv_label_set_text(ui_lteStatus,"Unkown");
//lv_obj_clear_flag( ui_lteStatus, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_lteStatus, LV_SCROLLBAR_MODE_OFF);

}


void ui_init(void)
{   
    display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
    if (!device_is_ready(display_dev)) {
        LOG_ERR("Device not ready, aborting test");
        return;
    }

    // lv_disp_t *dispp = lv_disp_get_default();
    // lv_theme_t *theme = lv_theme_mono_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    // lv_disp_set_theme(dispp, theme);

    ui_mqttScreen_screen_init();
    ui_lteScreen_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    //lv_disp_load_scr(ui_mqttScreen);

    lv_task_handler();
}
