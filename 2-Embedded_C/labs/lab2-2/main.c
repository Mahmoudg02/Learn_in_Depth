
#include <stdint.h>


typedef volatile uint32_t vuint32_t ;


#define RCC_BASE 			0x40021000
#define	GPIOA_BASE			0x40010800
#define RCC_APB2ENR			*(vuint32_t *)(RCC_BASE+0x18)
#define GPIOA_CHR 			*(vuint32_t *)(GPIOA_BASE+0x04)
#define GPIO_ODR			*(vuint32_t *)(GPIOA_BASE+0x0c)


#define RCC_IOPAEN 			(1<<2)
#define GPIOA_P13			(1ul<<13)
//bitfields 

typedef union {
	vuint32_t all_R ;
	struct 
	{
		vuint32_t reserved :13 ;
		vuint32_t p_13 :1 ;

	}pin;
}R_ODR_t ;


volatile uint8_t G_ARRAY[]={1,2,3,4,5,6,7,8,9} ;
volatile const uint8_t G_con_ARRAY[]={1,2,3,4,5,6,7,8,9} ;
volatile uint8_t G_un_ARRAY[10];


int main(void)
{
	volatile R_ODR_t* R_ODR = (volatile R_ODR_t *)(GPIOA_BASE+0x0C);
	
	RCC_APB2ENR|= RCC_IOPAEN ;
	GPIOA_CHR &=0xff0fffff ;
	GPIOA_CHR |=0x00200000 ;

	while(1)
	{	
	
		int i ;
		//GPIO_ODR&=(~GPIOA_P13);
		R_ODR->pin.p_13=0 ;
		for (i=0 ;i<5000;i++) ;
		//GPIO_ODR|=(GPIOA_P13);
		R_ODR->pin.p_13= 1;
		for (i=0 ;i<5000;i++) ;


	}


return 0 ;	
}
