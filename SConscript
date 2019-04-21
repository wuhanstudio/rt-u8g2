from building import *
import rtconfig

# get current directory
cwd     = GetCurrentDir()
# The set of source files associated with this SConscript file.
src     = Glob('inc/*.h')
src     = Glob('src/*.c')
src    += Glob('port/*.c')
src    += Glob('port/*.cpp')

if(GetDepend('PKG_USING_U8G2_V100') or GetDepend('PKG_USING_U8G2_V110') or GetDepend('PKG_USING_U8G2_V120')):
	if GetDepend('U8G2_USING_SW_I2C_SSD1306'):
		src    += Glob('examples/legacy/ssd1306_12864_sw_i2c_example.c')

	if GetDepend('U8G2_USING_HW_I2C_SSD1306'):
		src    += Glob('examples/legacy/ssd1306_12864_hw_i2c_example.c')

	if GetDepend('U8G2_USING_SW_SPI_SSD1306'):
		src    += Glob('examples/legacy/ssd1306_12864_4wire_sw_spi_example.c')

	if GetDepend('U8G2_USING_HW_SPI_SSD1306'):
		src    += Glob('examples/legacy/ssd1306_12864_4wire_hw_spi_example.c')

	if GetDepend('U8G2_USING_8080_ST7920'):
		src    += Glob('examples/legacy/st7920_12864_8080_example.c')

	if GetDepend('U8G2_USING_I2C_YL40'):
		src    += Glob('examples/yl_40_example.c')
else:
	if GetDepend('U8G2_USING_SW_I2C_SSD1306'):
		src    += Glob('examples/ssd1306_12864_sw_i2c_example.cpp')

	if GetDepend('U8G2_USING_HW_I2C_SSD1306'):
		src    += Glob('examples/ssd1306_12864_hw_i2c_example.cpp')

	if GetDepend('U8G2_USING_SW_SPI_SSD1306'):
		src    += Glob('examples/ssd1306_12864_4wire_sw_spi_example.cpp')

	if GetDepend('U8G2_USING_HW_SPI_SSD1306'):
		src    += Glob('examples/ssd1306_12864_4wire_hw_spi_example.cpp')

	if GetDepend('U8G2_USING_8080_ST7920'):
		src    += Glob('examples/st7920_12864_8080_example.cpp')

	if GetDepend('U8G2_USING_I2C_YL40'):
		src    += Glob('examples/yl_40_example.c')

path    = [cwd + '/']
path   += [cwd + '/port']

LOCAL_CCFLAGS = ''

group = DefineGroup('U8G2', src, depend = ['PKG_USING_U8G2'], CPPPATH = path, LOCAL_CCFLAGS = LOCAL_CCFLAGS)

Return('group')
