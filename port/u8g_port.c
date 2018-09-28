#include "u8g_port.h"

#define MAX_RETRY 3

static struct rt_i2c_bus_device *i2c_bus = RT_NULL;	

uint8_t u8x8_rt_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
  switch(msg)
  {
	case U8X8_MSG_DELAY_NANO:			// delay arg_int * 1 nano second
		__asm__ volatile("nop"); 
		break;    
	case U8X8_MSG_DELAY_100NANO:		// delay arg_int * 100 nano seconds
		__asm__ volatile("nop"); 
		break;
	case U8X8_MSG_DELAY_10MICRO:		// delay arg_int * 10 micro seconds
		for (uint16_t n = 0; n < 320; n++)
		{
			__asm__ volatile("nop"); 
		}
		break;
	case U8X8_MSG_DELAY_MILLI:			// delay arg_int * 1 milli second
		rt_thread_delay(arg_int);
		break;
	default:
		return 0;
  }
  return 1;
}

uint8_t u8x8_byte_rt_hw_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
	/* u8g2/u8x8 will never send more than 32 bytes between START_TRANSFER and END_TRANSFER */
	struct rt_i2c_msg msgs;
	static uint8_t buffer[32];		
	static uint8_t buf_idx;
	uint8_t *data;
	
	rt_uint8_t t = 0;	
	switch(msg)
	{
		case U8X8_MSG_BYTE_SEND:
			data = (uint8_t *)arg_ptr;      
			while( arg_int > 0 )
			{
				buffer[buf_idx++] = *data;
				data++;
				arg_int--;
			}
			break;
		case U8X8_MSG_BYTE_INIT:
			i2c_bus = rt_i2c_bus_device_find(I2C_DEVICE_NAME);
			if (i2c_bus == RT_NULL)
			{
				// rt_kprintf("Failed to find bus\n");
				return 0;
			}
			break;
		case U8X8_MSG_BYTE_SET_DC:
			break;
		case U8X8_MSG_BYTE_START_TRANSFER:
			// Set I2C Address
			//setI2CSlave(i2c_device, u8x8_GetI2CAddress(u8x8)>>1);
			buf_idx = 0;
			break;
		case U8X8_MSG_BYTE_END_TRANSFER:
			if (i2c_bus == RT_NULL)
			{
				rt_kprintf("Failed to find bus\n");
				return 0;
			}
			// I2C Data Transfer
			msgs.addr = u8x8_GetI2CAddress(u8x8)>>1;
			msgs.flags = RT_I2C_WR;
			msgs.buf = buffer;
			msgs.len = buf_idx;
			while(rt_i2c_transfer(i2c_bus, &msgs, 1) != 1 && t < MAX_RETRY)
			{
				t++;
			};
			if(t >= MAX_RETRY)
			{
				return 0;
			}
			break;
		default:
			return 0;
	}
	return 1;
}
