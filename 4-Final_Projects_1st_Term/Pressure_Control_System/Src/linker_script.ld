/*linkerscript for cortex m3
Mahmoud ashraf 
*/

MEMORY
{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 128K
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.vectors : {
		*(.vectors*)
		. = ALIGN(4);
	}>flash

	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata*)
		. = ALIGN(4);
		_E_TEXT = . ;
	}>flash

	.data : {
		_S_DATA = . ;
		*(.data*)
		. = ALIGN(4);
		_E_DATA = . ;
	}>sram AT>flash
	
	.bss : {
		_S_BSS = . ;
		*(.bss*)
		. = ALIGN(4);
		_E_BSS = . ;

		. = ALIGN(4);
		. = . + 0x2000 ;
		_STACK_TOP = . ;
	}>sram
}
