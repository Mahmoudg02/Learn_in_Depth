#include<stdint.h>

#define GPIOF_BASE 0x40025000
#define SYSCTL_BASE 0x400FE000

#define GPIO_PORTF_DATA_R 		*((volatile uint32_t*) (GPIOF_BASE+0x3FC))
#define GPIO_PORTF_DIR_R 		*((volatile uint32_t*) (GPIOF_BASE+0x400))
#define GPIO_PORTF_DEN_R 		*((volatile uint32_t*) (GPIOF_BASE+0x51C))

#define SYSCTL_RCGC2_R 			*((volatile uint32_t*) (SYSCTL_BASE+0x108))



int main(void)
{

	volatile uint32_t delay_count ;
	SYSCTL_RCGC2_R = 0x00000020 ;
	GPIO_PORTF_DIR_R |=(1<<3) ;
	GPIO_PORTF_DEN_R |=(1<<3) ;
	GPIO_PORTF_DATA_R &=~(1<<3);

	while(1)
	{
	GPIO_PORTF_DATA_R |=(1<<3);
	for(delay_count=0;delay_count<50000;delay_count++);
	GPIO_PORTF_DATA_R &=~(1<<3);
	for(delay_count=0;delay_count<50000;delay_count++);

	}



	return 0 ; 

}