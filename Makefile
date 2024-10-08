# Library management system build

# Complier
CC = gcc

# Flags
CFLAGS = -Wall -std=c99
GTKFLAGS = `pkg-config --cflags gtk+-3.0`

# Libs
LIBS= -lsqlite3
GTKLIBS = `pkg-config --libs gtk+-3.0`

all: main.o gui.o database.o
	${CC} ${CFLAGS} -o lms database.o gui.o main.o ${GTKLIBS} ${LIBS}

main.o: main.c 
	${CC} ${CFLAGS}	-o main.o -c main.c

gui.o: gui.c
	${CC} ${CFLAGS} ${GTKFLAGS}	-o gui.o -c gui.c ${GTKLIBS}

cli.o: cli.c
	${CC} ${CFLAGS} -o $@ -c $<

database.o: database.c
	${CC} ${CFLAGS} -o $@ -c $< ${LIBS}

run: all
	./lms

clean:
	rm -f lms *.o
