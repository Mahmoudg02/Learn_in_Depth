


CC= arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -gdwarf-2 -g -mthumb
INCS= -I .
#INS_SET= -mthumb
STD=
LIBS=
SRC	= $(wildcard *.c)
OBJ	= $(SRC:.c=.o)
As	= $(wildcard *.s)
AsOBJ = $(As:.s=.o)
LINKER = $(wildcard *.ld)
Project_Name =Tiva_C

all: $(Project_Name).bin
	@echo "================Build Successfully=============="
%.o: %.s
	$(CC)as.exe	$(CFLAGS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@ 

$(Project_Name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T $(LINKER) $(LIBS) $(OBJ) $(AsOBJ) $(INCS) -o $@ -Map=Map_file.map
	cp $(Project_Name).elf $(Project_Name).axf

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@

clean: 
	rm *.bin *.elf

clean_all:
	rm *.bin *.o *.map *.elf *.hex