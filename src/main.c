/*
 * Copyright (c) 2018 Jan Van Winkel <jan.van_winkel@dxplore.eu>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/display.h>
#include <zephyr/drivers/gpio.h>

#include <stdio.h>
#include <string.h>
#include <zephyr/kernel.h>

#include "display.h"
#include "ui_helpers.h"

#define LOG_LEVEL CONFIG_LOG_DEFAULT_LEVEL
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(app);


int main(void)
{
	ui_init();
	int i = 0;
	while (1)
	{
		switch(i)
		{
			case 0:
				lv_disp_load_scr(ui_mqttScreen);
				i = 1;
				break;
			case 1:
				lv_disp_load_scr(ui_lteScreen);
				i = 0;
				break;
			default:
				break;
		}
		lv_task_handler();
		k_sleep(K_MSEC(2000));
	}	
}
