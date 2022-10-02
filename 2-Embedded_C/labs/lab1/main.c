#include "UART.h"

char buff[100] = "mahmoud ashraf Learn with kerolos" ;
char const buff2[20]="mahmoud ashraf"  ;
void main(void)
{
	Uart_send_string(buff);

}
