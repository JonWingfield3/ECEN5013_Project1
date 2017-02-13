SRCS = project_1.c main.c memory.c data.c
OBJ_NAMES = $(SRCS:.c=.o)

INCLUDES = -I../includes -I$(OBJDIR) -I.
