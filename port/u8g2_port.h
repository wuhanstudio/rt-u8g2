#ifndef __U8G_PORT_H__
#define __U8G_PORT_H__

#include <rtthread.h>
#include <rtdevice.h>
#include <src/u8g2.h>

#define I2C_DEVICE_NAME "i2c2"
// You may reference Drivers/drv_gpio.c for pinout
#define PIN_CLK					20
#define PIN_MOSI				17
#define PIN_RES					16
#define PIN_DC					15
#define PIN_CS					14

uint8_t u8x8_byte_rt_hw_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);
uint8_t u8x8_rt_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);

#endif
