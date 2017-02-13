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
OBJS = ../objects/$(OBJ_NAMES)
LIBS = project1.a

# Set directory names
MISC := ../misc
OBJDIR := ../obj
LOGS := ../logs
LIBS := ../libs

# Make any object file
%.o : %.c | $(OBJDIR) $(LOGS)
	$(CC) -c $(@:.o=.c) -o $(OBJDIR)/$@
	@date +%T" Compiled $?" | tee -a $(LOGS)/makeLog.txt

# Make all object files
.PHONY : compile-all
compile-all : $(OBJ_NAMES)

# Make any preporcessed output file
%.i : %.c | $(MISC) $(LOGS)
	$(CC) -E $(@:.i=.c) -o $(MISC)/$@
	@date +%T" Created .i file for $?" | tee -a $(LOGS)/makeLog.txt

# Make any assembly output file
%.asm : %.c | $(MISC) $(LOGS)
	$(CC) -S $(@:.asm=.c) -o $(MISC)/$@
	@date +%T" Created .asm file for $?" | tee -a $(LOGS)/makeLog.txt

.PHONY : build
build: project1 project1.dep

.PHONY : project1
project1: $(OBJ_NAMES) $(LIBS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(addprefix $(OBJDIR)/,$(OBJ_NAMES)) -o $(OBJDIR)/$@
	size -A $(OBJDIR)/$@
	@date +%T" Built project" | tee -a $(LOGS)/makeLog.txt

libproject1.a: $(OBJ_NAMES) | $(LIBS)
	ar -rcs $(LIBS)/libproject1.a $(OBJDIR)/$(OBJ_NAMES)

project1.dep: $(SRCS) | $(MISC)
	$(CC) -MM $(SRCS) > $(MISC)/$@

.PHONY : clean
clean :
	-rm -f $(OBJDIR)/* $(MISC)/* ./project1.map
	@date +%T" Cleaned project space" | tee -a $(LOGS)/makeLog.txt

.PHONY : print
print: data.c main.c memory.c project_1.c | $(LOGS)
	@date +%T" $?" | tee -a $(LOGS)/print

$(MISC):
	mkdir $(MISC)

$(OBJDIR):
	mkdir $(OBJDIR)

$(LOGS):
	mkdir $(LOGS)

$(LIBS):
	mkdir $(LIBS)
