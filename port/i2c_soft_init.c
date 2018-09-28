#include "i2c_soft_init.h"

#ifdef SOC_STM32F1
#include <stm32f10x.h>
#endif

void stm32_set_sda(void *data, rt_int32_t state)
{
    // examples for STM32F103x
    #ifdef SOC_STM32F1
    if(state == 1)
        GPIO_SetBits(I2C1_GPIO , I2C1_GPIO_SDA);   //GPIOB->BSRRL = I2C1_GPIO_SDA
		// rt_pin_write(I2C1_GPIO_SDA,PIN_HIGH);
    else if(state == 0)
        GPIO_ResetBits(I2C1_GPIO , I2C1_GPIO_SDA); //GPIOB->BSRRH = I2C1_GPIO_SDA
		// rt_pin_write(I2C1_GPIO_SDA,PIN_LOW);
    #endif

    // If you are going to use software I2C, implement here

}

void stm32_set_scl(void *data, rt_int32_t state)
{
    // examples for STM32F103x
    #ifdef SOC_STM32F1
    if(state == 1)
		GPIO_SetBits(I2C1_GPIO , I2C1_GPIO_SCL);   //GPIOB->BSRRL = I2C1_GPIO_SCL
		// rt_pin_write(I2C1_GPIO_SCL,PIN_HIGH);
    else if(state == 0)
        GPIO_ResetBits(I2C1_GPIO , I2C1_GPIO_SCL); //GPIOB->BSRRH = I2C1_GPIO_SCL
		// rt_pin_write(I2C1_GPIO_SCL,PIN_LOW);
    #endif

    // If you are going to use software I2C, implement here

}

rt_int32_t stm32_get_sda(void *data)
{
    // examples for STM32F103x
    #ifdef SOC_STM32F1
        return (rt_int32_t)GPIO_ReadInputDataBit(I2C1_GPIO , I2C1_GPIO_SDA);//return(GPIOB->IDR  & I2C1_GPIO_SDA)
	#endif
    // return rt_pin_read(I2C1_GPIO_SDA);

    // If you are going to use software I2C, implement here

}

rt_int32_t stm32_get_scl(void *data)
{
    // examples for STM32F103x
    #ifdef SOC_STM32F1
        return (rt_int32_t)GPIO_ReadInputDataBit(I2C1_GPIO , I2C1_GPIO_SCL);//return(GPIOB->IDR  & I2C1_GPIO_SCL)
	#endif
    // return rt_pin_read(I2C1_GPIO_SCL);

    // If you are going to use software I2C, implement here

}

void stm32_udelay(rt_uint32_t us)
{
    // examples for STM32F103x
    #ifdef SOC_STM32F1
        rt_uint32_t delta;
        /* sysTick->LOAD=21000, RT_TICK_PER_SECOND=1000 */
        us = us * (SysTick->LOAD/(1000000/RT_TICK_PER_SECOND));
        delta = SysTick->VAL;
        /* delay us */
        while (delta - SysTick->VAL< us);
    #endif

    // If you are going to use software I2C, implement here

}

void stm32_mdelay(rt_uint32_t ms)
{
    // examples for STM32F103x
    #ifdef SOC_STM32F1
        stm32_udelay(ms * 1000);
    #endif

    // If you are going to use software I2C, implement here

}

static const struct  rt_i2c_bit_ops stm32_i2c_bit_ops =
{
    // examples for STM32F103x
    #ifdef SOC_STM32F1
        (void*)0xaa,     //no use in set_sda,set_scl,get_sda,get_scl
        stm32_set_sda,
        stm32_set_scl,
        stm32_get_sda,
        stm32_get_scl,
        stm32_udelay,
        20,
    #endif 

    // If you are going to use software I2C, implement here

};

static void RCC_Configuration(void)
{
    // examples for STM32F103x
    #ifdef SOC_STM32F1
	   RCC->APB2ENR|=1<<4;
	   RCC_APB2PeriphClockCmd( RCC_I2C, ENABLE );
    #endif

    // If you are going to use software I2C, implement here

}


static void GPIO_Configuration(void)
{
    // examples for STM32F103x
    #ifdef SOC_STM32F1
    	GPIO_InitTypeDef GPIO_InitStructure;
    	GPIO_InitStructure.GPIO_Pin = I2C1_GPIO_SDA | I2C1_GPIO_SCL;
    	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_OD ;
    	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;

    	GPIO_Init(I2C1_GPIO, &GPIO_InitStructure);
	#endif

	// rt_pin_mode(I2C1_GPIO_SDA, PIN_MODE_OUTPUT_OD);
	// rt_pin_mode(I2C1_GPIO_SCL, PIN_MODE_OUTPUT_OD);

    // If you are going to use software I2C, implement here

}

int rt_hw_i2c_init(void)
{
    static struct rt_i2c_bus_device stm32_i2c;
	  
    RCC_Configuration();
    GPIO_Configuration();
    
    rt_memset((void *)&stm32_i2c, 0, sizeof(struct rt_i2c_bus_device));
    stm32_i2c.priv = (void *)&stm32_i2c_bit_ops;
    rt_i2c_bit_add_bus(&stm32_i2c, "i2c1");   
        
    return 0;
}

#ifdef SOC_STM32F1
    // rt_hw_i2c_init will be called in rt_components_board_init()
    INIT_BOARD_EXPORT(rt_hw_i2c_init);  
#endif
