ifeq ($(PLATFORM),bbb)
	CC = arm-linux-gnueabi-gcc 
	CFLAGS = -g -Wall -Werror -O0 -std=$(STD)
else 
ifeq ($(PLATFORM),frdm)
	CC = arm-none-eabi-gcc
	CFLAGS = --specs=nosys.specs -g -Wall -Werror -O0 -std=$(STD)
else
	CC = gcc
	CFLAGS = -g -Wall -Werror -Wall -Werror -O0 -std=$(STD)
endif
endif


ifeq ($(shell uname),Darwin)
	LDFLAGS = -Wl,-map,project1.map
else
	LDFLAGS = -Wl,-Map=project1.map
endif

OS = $(shell uname)
STD = c99
#INCLUDES =
SRCS = main.c memory.c data.c
OBJS:=$(SRCS:.c=.o)

build: project1 project1.dep
	
project1: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o project1

project1.dep: $(SRCS)
	$(CC) -MM $(SRCS) > project1.dep

compile-all: $(OBJS)

main.o: main.c
	$(CC) -c main.c -o main.o

main.i: main.c
	$(CC) -E main.c -o main.i

main.asm: main.c
	$(CC) -S main.c -o main.asm

data.o: data.c
	$(CC) -c data.c -o data.o

data.i: data.c
	$(CC) -E data.c -o data.i 

data.asm: data.c
	$(CC) -S data.c -o data.asm

memory.o: memory.c
	$(CC) -c memory.c -o memory.o

memory.i: memory.c
	$(CC) -E memory.c -o memory.i

memory.asm: memory.c
	$(CC) -S memory.c -o memory.asm

clean:
	rm -f target_main host_main *.o *.dep *.d *.map *.s *.i *.out *.asm
