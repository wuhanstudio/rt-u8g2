![u8g2 logo](u8g2_logo.png)
# rt-u8g2 examples

## 1、介绍

> 说明：单色显示屏驱动在 rt-thread 上的移植。 

支持 SSD1305, SSD1306, SSD1309, SSD1322, SSD1325, SSD1327, SSD1329, SSD1606, SSD1607, SH1106, SH1107, SH1108, SH1122, T6963, RA8835, LC7981, PCD8544, PCF8812, HX1230, UC1601, UC1604, UC1608, UC1610, UC1611, UC1701, ST7565, ST7567, ST7588, ST75256, NT7534, IST3020, ST7920, LD7032, KS0108, SED1520, SBN1661, IL3820, MAX7219 等。

### 1.1 目录结构

> 说明：目录结构

| 名称 | 说明 |
| ---- | ---- |
| docs  | 文档目录 |
| examples | 例子目录|
| src  | 源代码目录 |
| port | 针对特定平台的移植代码目录 |

### 1.2 许可证

- The U8g2lib code (http://code.google.com/p/u8g2/) is licensed under the terms of 
the new-bsd license (two-clause bsd license).  See also:  

		http://www.opensource.org/licenses/bsd-license.php  

- The repository and optionally the releases contain icons, which are
derived from the WPZOOM Developer Icon Set. WPZOOM Developer Icon Set by WPZOOM is licensed under a Creative Commons 
Attribution-ShareAlike 3.0 Unported License.  

		http://www.wpzoom.com/wpzoom/new-freebie-wpzoom-developer-icon-set-154-free-icons/ 
 
- Fonts are licensed under different conditions.for detailed information on the licensing conditions for each font.
 
		https://github.com/olikraus/u8g2/wiki/fntgrp


Check full LICENCE **[here](LICENSE)**.

### 1.3 依赖

> 说明：如果使用 I2C 液晶屏需要开启 I2C，GPIO 模拟 I2C 。

- Using I2C device drivers
- Use GPIO to simulate I2C

> 说明：如果使用 SPI 液晶屏需要开启 SPI 。

- Using SPI Bus/Device device drivers

## 2、如何打开 U8G2

使用 u8g2 package 需要在 RT-Thread 的包管理器中选择它，具体路径如下：

	RT-Thread online packages
    	peripheral libraries and drivers --->
        	[*] U8G2: a u8g2 package for rt-thread


然后让 RT-Thread 的包管理器自动更新，或者使用 `pkgs --update` 命令更新包到 BSP 中。

## 3、使用 U8G2

> 说明： 如果使用的 bsp 是 STM32F10x 直接编译即可，参照[`/examples`](/examples/README.md)，其他平台请参照 [移植说明](port/README.md) 

在打开 u8g2 package 后，当进行 bsp 编译时，它会被加入到 bsp 工程中进行编译。

* 移植请参照 [`/port`](/port) 下
* 完整的 API 手册可以访问这个[链接](https://github.com/olikraus/u8g2/wiki/u8g2reference)

## 4、注意事项

- 默测试认使用 STM32F10x，如果要使用到其他平台，请参照 [移植说明](port/README.md)。

- 如果直接使用的 rt-thread 应当不需要额外移植。

- 编译需要开启 -std=c99

## 5、感谢

- u8g2: https://github.com/olikraus/u8g2

## 6、联系方式

* 维护：Wu Han
* 主页：http://wuhanstudio.cc
* 邮箱：wuhanstudio@hust.edu.cn
