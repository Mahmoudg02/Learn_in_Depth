


CC= arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2 -mthumb
INCS= -I .
#INS_SET= -mthumb
STD=
LIBS=
SRC	= $(wildcard *.c)
OBJ	= $(SRC:.c=.o)
As	= $(wildcard *.s)
AsOBJ = $(As:.s=.o)
LINKER = $(wildcard *.ld)
Project_Name =Pressure_Control_system

all: $(Project_Name).bin
	@echo "================Build Successfully=============="

%.o: %.s
	$(CC)as.exe	$(CFLAGS) $< -o $@ 
	@echo "---->> Generate object files from assembly files "

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@ 
	@echo "---->> Generate object files from C files "

$(Project_Name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T $(LINKER) $(LIBS) $(OBJ) $(AsOBJ) $(INCS) -o $@ -Map=Map_file.map
	@echo "---->> Finish linking Process and generate .map , .elf "

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@
	@echo "---->> Generate binary file from elf file  "


clean: 
	@echo "---->> Clean only bin , elf files  "
	rm *.bin *.elf


clean_all:
	@echo "---->> Clean all generated files   "
	rm *.bin *.o *.map *.elf *.hex *.asm
