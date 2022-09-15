ENTRY(reset)
MEMORY
{
	Mem (rwx) : ORIGIN = 0X00000000, LENGTH = 64M
}
SECTIONS 
{	. = 0x10000 ;
	.reset . :
	{
		startup.o(.text)
	}>Mem
	.text :
	{
		*(.text) *(.rodata)
	}>Mem
	.data :
	{
		*(.data) *(.COMMON)
	}>Mem
	.bss : 
	{
		*(.bss) 
	}>Mem
	
	. = . + 0x1000 ;
	stack_top = . ;
}
