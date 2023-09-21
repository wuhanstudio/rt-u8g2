from building import *
import rtconfig

# get current directory
cwd     = GetCurrentDir()

# The set of source files associated with this SConscript file.
src     = Glob('src/*.c')
src    += Glob('port/*.c')

if(GetDepend('U8G2_USE_CPP')):
	src    += Glob('port/*.cpp')

if(not GetDepend('U8G2_USE_CPP')):

	if GetDepend('U8G2_USING_SW_I2C_SSD1306'):
		src    += Glob('examples/ssd1306_12864_sw_i2c_example.c')

	if GetDepend('U8G2_USING_HW_I2C_SSD1306'):
		src    += Glob('examples/ssd1306_12864_hw_i2c_example.c')

	if GetDepend('U8G2_USING_SW_SPI_SSD1306'):
		src    += Glob('examples/ssd1306_12864_4wire_sw_spi_example.c')

	if GetDepend('U8G2_USING_HW_SPI_SSD1306'):
		src    += Glob('examples/ssd1306_12864_4wire_hw_spi_example.c')

	if GetDepend('U8G2_USING_8080_ST7920'):
		src    += Glob('examples/st7920_12864_8080_example.c')

	if GetDepend('U8G2_USING_I2C_YL40'):
		src    += Glob('examples/yl_40_example.c')

else:

	# Basic Examples
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


	# Frame Buffer Examples
	if GetDepend('U8G2_USING_FRAME_EXAMPLE_FONT_USAGE'):
		src    += Glob('examples/full_buffer/FontUsage.cpp')

	if GetDepend('U8G2_USING_FRAME_EXAMPLE_FPS'):
		src    += Glob('examples/full_buffer/FPS.cpp')

	if GetDepend('U8G2_USING_FRAME_EXAMPLE_GRAPHIC_TEST'):
		src    += Glob('examples/full_buffer/GraphicsTest.cpp')

	if GetDepend('U8G2_USING_FRAME_EXAMPLE_HELLO_WORLD'):
		src    += Glob('examples/full_buffer/HelloWorld.cpp')

	if GetDepend('U8G2_USING_FRAME_EXAMPLE_ICON_MENU'):
		src    += Glob('examples/full_buffer/IconMenu.cpp')

	if GetDepend('U8G2_USING_FRAME_EXAMPLE_PRINT_UTF8'):
		src    += Glob('examples/full_buffer/PrintUTF8.cpp')

	if GetDepend('U8G2_USING_FRAME_EXAMPLE_SELECTION_LIST'):
		src    += Glob('examples/full_buffer/SelectionList.cpp')

	if GetDepend('U8G2_USING_FRAME_EXAMPLE_U8G2_LOGO'):
		src    += Glob('examples/full_buffer/U8g2Logo.cpp')

	if GetDepend('U8G2_USING_FRAME_EXAMPLE_UPDATE_AREA'):
		src    += Glob('examples/full_buffer/UpdateArea.cpp')

	if GetDepend('U8G2_USING_FRAME_EXAMPLE_WEATHER'):
		src    += Glob('examples/full_buffer/Weather.cpp')


	# Page Buffer Examples
	if GetDepend('U8G2_USING_PAGE_EXAMPLE_CHINESE'):
		src    += Glob('examples/page_buffer/Chinese.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_CLIP_WINDOW'):
		src    += Glob('examples/page_buffer/ClipWindow.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_CLOCK'):
		src    += Glob('examples/page_buffer/Clock.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_CONTRAST_TEST'):
		src    += Glob('examples/page_buffer/ContrastTest.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_DEVANAGARI'):
		src    += Glob('examples/page_buffer/Devanagari.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_DIRECT_ACCESS'):
		src    += Glob('examples/page_buffer/DirectAccess.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_DRAW_LOG'):
		src    += Glob('examples/page_buffer/DrawLog.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_EXT_UTF8'):
		src    += Glob('examples/page_buffer/ExtUTF8.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_FLIP_MODE'):
		src    += Glob('examples/page_buffer/FlipMode_pb.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_FPS'):
		src    += Glob('examples/page_buffer/FPS_pb.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_GRAPHIC_TEST'):
		src    += Glob('examples/page_buffer/GraphicsTest_pb.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_HELLO_WORLD'):
		src    += Glob('examples/page_buffer/HelloWorld_pb.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_ICON_MENU'):
		src    += Glob('examples/page_buffer/IconMenu_pb.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_JAPANESE'):
		src    += Glob('examples/page_buffer/Japanese.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_KOREAN'):
		src    += Glob('examples/page_buffer/Korean.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_POWER_SAVE_TEST'):
		src    += Glob('examples/page_buffer/PowerSaveTest.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_PRINT_HELLO_WORLD'):
		src    += Glob('examples/page_buffer/PrintHelloWorld.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_SCROLLING_TEXT'):
		src    += Glob('examples/page_buffer/ScrollingText.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_SELECTION_LIST'):
		src    += Glob('examples/page_buffer/SelectionList_pb.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_SERIAL'):
		src    += Glob('examples/page_buffer/Serial.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_STATE_BUFFER_LOOP'):
		src    += Glob('examples/page_buffer/StateBufferLoop.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_TERMINAL'):
		src    += Glob('examples/page_buffer/Terminal_pb.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_U8G2_LOGO'):
		src    += Glob('examples/page_buffer/U8g2Logo_pb.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_UPDATE_PARTLY'):
		src    += Glob('examples/page_buffer/UpdatePartly_pb.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_WEATHER'):
		src    += Glob('examples/page_buffer/Weather_pb.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_XBM'):
		src    += Glob('examples/page_buffer/XBM.cpp')

	if GetDepend('U8G2_USING_PAGE_EXAMPLE_XOR_TEST'):
		src    += Glob('examples/page_buffer/XORTest.cpp')


	# U8x8 Examples
	if GetDepend('U8G2_USING_U8x8_EXAMPLE_16x16_FONT'):
		src    += Glob('examples/u8x8/16x16Font.cpp')

	if GetDepend('U8G2_USING_U8x8_EXAMPLE_FLIP_MODE'):
		src    += Glob('examples/u8x8/FlipMode.cpp')

	if GetDepend('U8G2_USING_U8x8_EXAMPLE_GRAPHIC_TEST'):
		src    += Glob('examples/u8x8/GraphicsTest_8x8.cpp')

	if GetDepend('U8G2_USING_U8x8_EXAMPLE_HELLO_WORLD'):
		src    += Glob('examples/u8x8/HelloWorld_8x8.cpp')

	if GetDepend('U8G2_USING_U8x8_EXAMPLE_MESSAGE_BOX'):
		src    += Glob('examples/u8x8/MessageBox_8x8.cpp')

	if GetDepend('U8G2_USING_U8x8_EXAMPLE_TERMINAL'):
		src    += Glob('examples/u8x8/Terminal_8x8.cpp')


	# Game Examples
	if GetDepend('U8G2_USING_GAME_EXAMPLE_SPACE_TRASH'):
		src    += Glob('examples/games/SpaceTrash.cpp')
	if GetDepend('U8G2_USING_GAME_EXAMPLE_TREX'):
		src    += Glob('examples/games/TRex.cpp')

path    = [cwd + '/']
path   += [cwd + '/port']
path   += [cwd + '/src']

LOCAL_CCFLAGS = ''

group = DefineGroup('U8G2', src, depend = ['PKG_USING_U8G2'], CPPPATH = path, LOCAL_CCFLAGS = LOCAL_CCFLAGS, CPPDEFINES=['RTT_U8G2'])

Return('group')
