![u8g2 logo](u8g2_logo.png)
# rt-u8g2

## ssd1306_example.c

编译后在 msh 输入 ssd1306_example 就会在液晶屏 (I2C ssd1306) 上显示出文字和图案。 

	msh> ssd1306_example

<img src=u8g2.jpg width=600>

## yl_40-_example.c

通过调整 YL-40 模块 LED 的亮度，测试 I2C 总线是否正常工作。

	msh> yl_40_example 255        #          
	msh> yl_40_example 0x48 255   # [I2C 地址] [数据]
 