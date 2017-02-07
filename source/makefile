ifeq ($(shell uname),Darwin) # on macbook
	LDFLAGS = -Wl,-map,project1.map
ifeq ($(PLATFORM),bbb) # cross compiling for bbb
	CC = arm-linux-gnueabi-gcc
	CFLAGS = -g Wall -Werror -O0 -std=$(STD)
endif
ifeq ($(PLATFORM),frdm) # cross compiling for Freedom KL25z
	CC= arm-none-eabi-gcc
	CFLAGS= --specs=nosys.specs -g -Wall -Werror -O0 -std=$(STD)
else # native compilation for x86_64, default option
	CC = gcc
endif
else # native compilation for bbb
	LDFLAGS = -Wl,-Map=project1.map
	CC = gcc
endif

OS = $(shell uname)
STD = c99
INCLUDES = -I../includes -I../objects -I.
SRCS = project_1.c main.c memory.c data.c
OBJ_NAMES = $(SRCS:.c=.o)
OBJS = ../objects/$(OBJ_NAMES) 
LIBS = project1.a
build: project1 project1.dep	

project1: $(OBJ_NAMES) $(LIBS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(OBJS) -o ../objects/project1
	size -A $(OBJS)	

libproject1.a: $(OBJ_NAMES)
	ar -rcs ../libs/libproject1.a $(OBJS)

project1.dep: $(SRCS)
	$(CC) -MM $(SRCS) > ../misc/project1.dep

compile-all: $(OBJ_NAMES)

main.o: main.c
	$(CC) -c $(INCLUDES) main.c -o ../objects/main.o

main.i: main.c
	$(CC) -E $(INCLUDES) main.c -o ../misc/main.i

main.asm: main.c
	$(CC) -S $(INCLUDES) main.c -o ../misc/main.asm

data.o: data.c
	$(CC) -c $(INCLUDES) data.c -o ../objects/data.o

data.i: data.c
	$(CC) -E $(INCLUDES) data.c -o ../misc/data.i 

data.asm: data.c
	$(CC) -S $(INCLUDES) data.c -o ../misc/data.asm

memory.o: memory.c
	$(CC) -c $(INCLUDES) memory.c -o ../objects/memory.o

memory.i: memory.c
	$(CC) -E $(INCLUDES) memory.c -o ../misc/memory.i

memory.asm: memory.c
	$(CC) -S $(INCLUDES) memory.c -o ../misc/memory.asm

project_1.o: project_1.c
	$(CC) -c $(INCLUDES) project_1.c -o ../objects/project_1.o

project_1.i: project_1.c
	$(CC) -E $(INCLUDES) project_1.c -o ../misc/project_1.i

project_1.asm: project_1.c
	$(CC) -S $(INCLUDES) project_1.c -o ../misc/project_1.asm

clean:
	rm -f ../objects/project1 ../objects/*.o ../misc/*.dep ../misc*.map ../misc/*.i ../objects/*.out ../misc/*.asm


