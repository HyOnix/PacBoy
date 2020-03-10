GCC= gcc
CFLAGS = -Wall -Werror -no-pie
CLIBS = -lglut -lGL -lGLU  -lm -lX11
INCLUDES =

all: EXE
	./EXE

EXE: main.c c/libisentlib.a  c/mes_fonctions.c 
	$(GCC) $(CFLAGS) main.c c/mes_fonctions.c  c/libisentlib.a -o EXE  $(INCLUDES) $(CLIBS)


clean:
	rm -f main
	rm -f *.o
