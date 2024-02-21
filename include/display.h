#ifndef __DISPLAY_H
#define __DISPLAY_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <lvgl.h>

// SCREEN: ui_mqttScreen
void ui_mqttScreen_screen_init(void);
extern lv_obj_t *ui_mqttScreen;
extern lv_obj_t *ui_mqttTag;
extern lv_obj_t *ui_mqttStatus;
// SCREEN: ui_lteScreen
void ui_lteScreen_screen_init(void);
extern lv_obj_t *ui_lteScreen;
extern lv_obj_t *ui_lteTag;
extern lv_obj_t *ui_lteStatus;
extern lv_obj_t *ui____initial_actions0;
// SCREEN: ui_channelsScreen
void ui_channelsScreen_screen_init(void);
extern lv_obj_t *ui_channelsScreen;
extern lv_obj_t *ui_channelsTag;
extern lv_obj_t *ui_channelsStatus;
extern lv_obj_t *ui____initial_actions1;


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif