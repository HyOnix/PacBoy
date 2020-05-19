GCC= gcc
CFLAGS = -Wall -Werror -no-pie
CLIBS = -lX11 -lglut -lm -lGL -lGLU -lSDL_mixer
INCLUDES = c/libisentlib.a c/mes_fonctions.c c/fonctions_menu.c

all: EXE
	clear
	./EXE

EXE: main.c c/libisentlib.a  c/mes_fonctions.c c/fonctions_menu.c
	$(GCC) $(CFLAGS) main.c $(INCLUDES) -o EXE $(CLIBS)


clean:
	rm -f main
	rm -f *.o
