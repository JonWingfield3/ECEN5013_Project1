main: main.c memory.c memory.h
	arm-none-eabi-gcc --specs=nosys.specs -Wl,-Map=main.map memory.c main.c -o main

clean:
	rm -f main *.o *.dep *.d *.map
