main: main.c memory.c memory.h
	arm-none-eabi-gcc --specs=nosys.specs -Wl,-Map=main.map -sysmemory.c main.c -o main
