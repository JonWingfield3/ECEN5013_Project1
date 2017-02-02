target_main: main.c memory.c data.c
	arm-none-eabi-gcc --specs=nosys.specs -Wl,-Map=main.map data.c memory.c main.c -o target_main

host_main: main.c memory.c data.c
	gcc main.c memory.c data.c -o host_main

clean:
	rm -f target_main host_main *.o *.dep *.d *.map
