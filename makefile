COMMON=./common/
OBJDIR=./obj/
CC=gcc
LD=gcc
CFLAGS=-c -I$(COMMON) -O3 -Wall
LDFLAGS=
COMMONOBJS=$(OBJDIR)utils.o $(OBJDIR)ecodes.o $(OBJDIR)arena.o $(OBJDIR)conio.o
NAME1=episode2quest1
EXES=$(NAME1)

all: $(EXES)

$(NAME1): $(OBJDIR)$(NAME1).o $(COMMONOBJS)
	$(LD) $(LDFLAGS) $(OBJDIR)$(NAME1).o $(COMMONOBJS) -o $(NAME1)


$(OBJDIR)$(NAME1).o: $(NAME1).c
	$(CC) $(CFLAGS) $(NAME1).c -o $(OBJDIR)$(NAME1).o


$(OBJDIR)utils.o: $(COMMON)utils.c $(COMMON)utils.h
	$(CC) $(CFLAGS) -o$(OBJDIR)utils.o $(COMMON)utils.c

$(OBJDIR)ecodes.o: $(COMMON)ecodes.c $(COMMON)ecodes.h
	$(CC) $(CFLAGS) -o$(OBJDIR)ecodes.o $(COMMON)ecodes.c

$(OBJDIR)arena.o: $(COMMON)arena.c $(COMMON)arena.h
	$(CC) $(CFLAGS) -o$(OBJDIR)arena.o $(COMMON)arena.c

$(OBJDIR)conio.o: $(COMMON)conio.c $(COMMON)conio.h
	$(CC) $(CFLAGS) -o$(OBJDIR)conio.o $(COMMON)conio.c

clean:
	rm $(OBJDIR)*.o
	rm $(NAME1)

