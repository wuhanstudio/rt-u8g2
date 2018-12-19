#include "u8g2_port.h"

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
		
		case U8X8_MSG_GPIO_AND_DELAY_INIT:  
			//Function which implements a delay, arg_int contains the amount of ms  
			//set mode 
			rt_pin_mode(PIN_CLK,PIN_MODE_OUTPUT);//d0 a5 15 d1 a7 17 res b0 18 dc b1 19 cs a4 14  
			rt_pin_mode(PIN_MOSI,PIN_MODE_OUTPUT);
			rt_pin_mode(PIN_RES,PIN_MODE_OUTPUT);
			rt_pin_mode(PIN_DC,PIN_MODE_OUTPUT);
			rt_pin_mode(PIN_CS,PIN_MODE_OUTPUT);
			//set value
			rt_pin_write(PIN_CLK,1);
			rt_pin_write(PIN_MOSI,1);
			rt_pin_write(PIN_RES,1);
			rt_pin_write(PIN_DC,1);
			rt_pin_write(PIN_CS,1);
			break;
							
		case U8X8_MSG_GPIO_SPI_CLOCK:  
			//Function to define the logic level of the clockline  
			if (arg_int) rt_pin_write(PIN_CLK,1);  
			else rt_pin_write(PIN_CLK,0);
			break;
							
		case U8X8_MSG_GPIO_SPI_DATA:
			//Function to define the logic level of the data line to the display  
			if (arg_int) rt_pin_write(PIN_MOSI,1);  
			else rt_pin_write(PIN_MOSI,0);  
			break;

		case U8X8_MSG_GPIO_CS:
			// Function to define the logic level of the CS line  
			if(arg_int)		rt_pin_write(PIN_CS,1);
			else		rt_pin_write(PIN_CS,0);
			break;

		case U8X8_MSG_GPIO_DC:
			//Function to define the logic level of the Data/ Command line  
			if(arg_int) rt_pin_write(PIN_DC,1);
			else rt_pin_write(PIN_DC,0);
			break;  

		case U8X8_MSG_GPIO_RESET:
			//Function to define the logic level of the RESET line
			if (arg_int) rt_pin_write(PIN_RES,1);
			else rt_pin_write(PIN_RES,0);
			break;

		default:  
			//A message was received which is not implemented, return 0 to indicate an error 
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
			buf_idx = 0;
			break;
		case U8X8_MSG_BYTE_END_TRANSFER:
			if (i2c_bus == RT_NULL)
			{
				rt_kprintf("Failed to find bus\n");
				return 0;
			}
			// I2C Data Transfer
			msgs.addr  = u8x8_GetI2CAddress(u8x8)>>1;
			msgs.flags = RT_I2C_WR;
			msgs.buf   = buffer;
			msgs.len   = buf_idx;
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
