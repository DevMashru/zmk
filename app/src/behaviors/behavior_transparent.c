/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#define DT_DRV_COMPAT zmk_behavior_transparent

#include <device.h>
#include <power/reboot.h>
#include <drivers/behavior.h>
#include <logging/log.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

struct behavior_transparent_config {};
struct behavior_transparent_data {};

static int behavior_transparent_init(struct device *dev) { return 0; };

static int on_keymap_binding_pressed(struct device *dev, u32_t position, u32_t _param1,
                                     u32_t _param2) {
    return 1;
}

static int on_keymap_binding_released(struct device *dev, u32_t position, u32_t _param1,
                                      u32_t _param2) {
    return 1;
}

static const struct behavior_driver_api behavior_transparent_driver_api = {
    .binding_pressed = on_keymap_binding_pressed,
    .binding_released = on_keymap_binding_released,
};

static const struct behavior_transparent_config behavior_transparent_config = {};

static struct behavior_transparent_data behavior_transparent_data;

DEVICE_AND_API_INIT(behavior_transparent, DT_INST_LABEL(0), behavior_transparent_init,
                    &behavior_transparent_data, &behavior_transparent_config, APPLICATION,
                    CONFIG_KERNEL_INIT_PRIORITY_DEFAULT, &behavior_transparent_driver_api);