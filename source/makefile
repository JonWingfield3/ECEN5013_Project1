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

include sources.mk

OS = $(shell uname)
STD = c99
INCLUDES = -I../includes -I../objects -I.
SRCS = project_1.c main.c memory.c data.c
OBJ_NAMES = $(SRCS:.c=.o)
OBJS = ../objects/$(OBJ_NAMES)
LIBS = project1.a

# Set directory names
MISC := ../misc
OBJDIR := ../obj
LOGS := ../logs

# Make any object file
%.o : %.c | $(OBJDIR) $(LOGS)
	$(CC) -c $(@:.o=.c) -o $(OBJDIR)/$@
	@date +%T" Compiled $?" | tee -a $(LOGS)/makeLog

.PHONY : compile-all
compile-all : $(OBJ_NAMES)

build: project1 project1.dep

.PHONY : project1
project1: $(OBJ_NAMES) $(LIBS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(OBJS) -o $(OBJDIR)/project1
	size -A $(OBJS)

libproject1.a: $(OBJ_NAMES)
	ar -rcs ../libs/libproject1.a $(OBJS)

project1.dep: $(SRCS) | $(MISC)
	$(CC) -MM $(SRCS) > $(MISC)/project1.dep

main.i: main.c | $(MISC)
	$(CC) -E $(INCLUDES) main.c -o $(MISC)/main.i

main.asm: main.c | $(MISC)
	$(CC) -S $(INCLUDES) main.c -o $(MISC)/main.asm

data.i: data.c | $(MISC)
	$(CC) -E $(INCLUDES) data.c -o $(MISC)/data.i

data.asm: data.c | $(MISC)
	$(CC) -S $(INCLUDES) data.c -o $(MISC)/data.asm

memory.i: memory.c | $(MISC)
	$(CC) -E $(INCLUDES) memory.c -o $(MISC)/memory.i

memory.asm: memory.c | $(MISC)
	$(CC) -S $(INCLUDES) memory.c -o $(MISC)/memory.asm

project_1.i: project_1.c | $(MISC)
	$(CC) -E $(INCLUDES) project_1.c -o $(MISC)/project_1.i

project_1.asm: project_1.c | $(MISC)
	$(CC) -S $(INCLUDES) project_1.c -o $(MISC)/project_1.asm

.PHONY : clean
clean :
	-rm -f $(OBJDIR)/project1 $(OBJDIR)/*.o $(MISC)/*.dep $(MISC)/*.map $(MISC)/*.i $(OBJDIR)/*.out $(MISC)/*.asm

.PHONY : print
print: data.c main.c memory.c project_1.c | $(LOGS)
	@date +%T" $?" | tee -a $(LOGS)/print

$(MISC):
	mkdir $(MISC)

$(OBJDIR):
	mkdir $(OBJDIR)

$(LOGS):
	mkdir $(LOGS)
