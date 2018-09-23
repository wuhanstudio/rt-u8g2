![u8g2 logo](u8g2_logo.png)

# rt-u8g2 移植

## 1. I2C 初始化

完成这部分的移植上电后 list_device 应当能看到 i2c1 总线。

	void stm32_set_sda(void *data, rt_int32_t state)  

设置 SDA (GPIO 模拟) 的引脚高低电平

	void stm32_set_scl(void *data, rt_int32_t state)

设置 SCL (GPIO 模拟) 的引脚高低电平

	rt_int32_t stm32_get_sda(void *data)

获取 SDA (GPIO 模拟) 的引脚高低电平

	rt_int32_t stm32_get_scl(void *data)

获取 SCL (GPIO 模拟) 的引脚高低电平

	void stm32_udelay(rt_uint32_t us)

延时微妙

	void stm32_mdelay(rt_uint32_t ms)

延时毫秒

	static void RCC_Configuration(void)

初始化时钟

	static void GPIO_Configuration(void)

初始化引脚

## 2. u8g2 移植

这部分主要是完成 u8g2 HAL 层的移植, 可以参照 [这里](https://github.com/olikraus/u8g2/wiki/Porting-to-new-MCU-platform)。

	uint8_t u8x8_byte_rt_hw_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);

I2C 相关的操作

	uint8_t u8x8_rt_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);

GPIO 和 延时 相关的操作