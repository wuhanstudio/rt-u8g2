from building import *
import rtconfig

# get current directory
cwd     = GetCurrentDir()
# The set of source files associated with this SConscript file.
src     = Glob('inc/*.h')
src     = Glob('src/*.c')
src    += Glob('port/*.c')

if GetDepend('U8G2_USING_I2C_SSD1306'):
	src    += Glob('examples/ssd1306_example.c')

if GetDepend('U8G2_USING_I2C_YL40'):
	src    += Glob('examples/yl_40_example.c')

path    = [cwd + '/']
path   += [cwd + '/port']

LOCAL_CCFLAGS = ''

if rtconfig.CROSS_TOOL == 'gcc':
    LOCAL_CCFLAGS += ' -std=c99'
elif rtconfig.CROSS_TOOL == 'keil':
    LOCAL_CCFLAGS += '-O2 --c99 --gnu'

group = DefineGroup('U8G2', src, depend = ['PKG_USING_U8G2'], CPPPATH = path, LOCAL_CCFLAGS = LOCAL_CCFLAGS)

Return('group')
