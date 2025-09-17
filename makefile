TCFOLDER=C:\TC
COMMON=COMMON
OBJDIR=OBJ
MODEL=s
CC=tcc
LD=tlink
AR=tlib
CFLAGS=-c -m$(MODEL) -I$(COMMON)
XXCFLAGS=-c -O2 -G -Z -m$(MODEL) -I$(COMMON)
LDFLAGS=/L$(TCFOLDER)\LIB $(TCFOLDER)\LIB\c0s.obj
COMMONOBJS=$(OBJDIR)\utils.obj $(OBJDIR)\ecodes.obj $(OBJDIR)\arena.obj
NAME=e2q01
EXE=$(NAME).exe
MAP=$(OBJDIR)\$(NAME).map
xlflags=c:\tc\lib\c0s.obj
xlibs=c:\tc\lib\cs.lib c:\tc\lib\maths.lib c:\tc\lib\fp87.lib

all: $(EXE)

$(EXE): $(NAME).obj $(COMMONOBJS)
	$(LD) $(LDFLAGS) $(OBJDIR)\$(NAME).obj $(COMMONOBJS),$(EXE),$(MAP),@libs.rsp


$(NAME).obj: $(NAME).c
	$(CC) $(CFLAGS) -o$(OBJDIR)\$(NAME).obj $(NAME).c

$(OBJDIR)\utils.obj: $(COMMON)\utils.c $(COMMON)\utils.h
	$(CC) $(CFLAGS) -o$(OBJDIR)\utils.obj $(COMMON)\utils.c

$(OBJDIR)\ecodes.obj: $(COMMON)\ecodes.c $(COMMON)\ecodes.h
	$(CC) $(CFLAGS) -o$(OBJDIR)\ecodes.obj $(COMMON)\ecodes.c

$(OBJDIR)\arena.obj: $(COMMON)\arena.c $(COMMON)\arena.h
	$(CC) $(CFLAGS) -o$(OBJDIR)\arena.obj $(COMMON)\arena.c 

clean:
	del $(OBJDIR)\*.obj
	del $(OBJDIR)\*.map
	del *.bak
	del *.exe

