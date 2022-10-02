

//cortex-m3 startup.c 
//By mahmoud ashraf

#include <stdint.h>
extern int main(void);
extern uint32_t _STACK_TOP ;

 void Reset_Handler(void);
 void Default_Handler(void){
	Reset_Handler() ;
}

// void H_fault_Handler(void){
// 	Reset_Handler() ;
// }
// void MM_fault_Handler(void){
// 	Reset_Handler() ;
// }
// void Bus_fault_Handler(void){
// 	Reset_Handler() ;
// }
// void Usage_fault_Handler(void){
// 	Reset_Handler() ;
// }

void H_fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void MM_fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void Bus_fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void Usage_fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));



uint32_t vectors[] __attribute__ ((section(".vectors"))) = {
(uint32_t)&_STACK_TOP ,
(uint32_t)&Reset_Handler ,
(uint32_t)&H_fault_Handler ,
(uint32_t)&MM_fault_Handler ,
(uint32_t)&Bus_fault_Handler ,
(uint32_t)&Usage_fault_Handler ,
};

extern uint32_t _E_TEXT	;
extern uint32_t _S_DATA ;	
extern uint32_t _E_DATA	;
extern uint32_t _S_BSS 	;
extern uint32_t _E_BSS  ;

void Reset_Handler(void)
{	uint32_t BSS_size  = (uint32_t)((uint8_t*)&_E_BSS - (uint8_t*)&_S_BSS) ;
	uint32_t Data_size = (uint32_t)((uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA) ;
	uint8_t *P_src = (uint8_t *) &_E_TEXT ;
	uint8_t *P_dst = (uint8_t *) &_S_DATA  ;

// copy data frpm flash to ram section  .

	uint32_t count  ;
	for(count = 0 ; count < Data_size ; count ++)
	{
		(*(uint8_t *)P_dst++) = (*(uint8_t *)P_src++) ;
	}

// intialize ram with zero's 

	*P_dst = (uint8_t*)&_S_BSS ;
	for(count = 0 ;count < BSS_size ;count ++)
	{
		*((uint8_t*)P_dst++) = (uint8_t)0 ;
	}

	main();
}