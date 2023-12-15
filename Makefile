# Library management system build

# Complier
CC = gcc

# Flags
CFLAGS = -Wall -std=c99
GTKFLAGS = `pkg-config --cflags gtk+-3.0`

# Libs
GTKLIBS = `pkg-config --libs gtk+-3.0`

all: gui.o main.o
	${CC} ${CFLAGS} -o lms gui.o main.o ${GTKLIBS}

main.o: main.c
	${CC} ${CFLAGS} ${GTKFLAGS}	-o $@ -c $< ${GTKLIBS}

gui.o: gui.c
	${CC} ${CFLAGS} ${GTKFLAGS}	-o $@ -c $< ${GTKLIBS}

database.o: database.c
	${CC} ${CFLAGS} -o $@ -c $<

run:
	./lms

clean:
	rm lms *.o
