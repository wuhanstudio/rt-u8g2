#include <rthw.h>
#include <rtthread.h>
#include <rtdevice.h>
#include <stdlib.h>
#include <u8g2_port.h>

static void yl_40_example(int argc, char *argv[])
{
    struct rt_i2c_bus_device *yl40_bus = RT_NULL;

    yl40_bus = rt_i2c_bus_device_find(U8G2_I2C_DEVICE_NAME);

    rt_uint8_t t = 0;
    if (yl40_bus == RT_NULL)
    {
        rt_kprintf("Failed to find bus\n");
    }
    else
    {
        struct rt_i2c_msg msgs;
        static uint8_t buffer[2];
        buffer[0] = 0xff;
        if(argc == 2)
        {
            buffer[1] = atoi(argv[1]);
        }
        else if(argc == 3)
        {
            buffer[1] = atoi(argv[2]);
        }
        else
        {
            buffer[1] = 0x88;
        }

        if(argc >= 3)
        {
            msgs.addr = (int)strtol(argv[1], NULL, 0);
        }
        else
        {
            msgs.addr = 0x48;
        }

        msgs.flags = RT_I2C_WR;
        msgs.buf = buffer;
        msgs.len = 2;
        while(rt_i2c_transfer(yl40_bus, &msgs, 1) != 1 && t < 3)
        {
            t++;
        };
    }
}
MSH_CMD_EXPORT(yl_40_example, i2c yl-40 sample);
