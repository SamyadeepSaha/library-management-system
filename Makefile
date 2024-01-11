# Library management system build

# Complier
CC = gcc

# Flags
CFLAGS = -Wall -std=c99
GTKFLAGS = `pkg-config --cflags gtk+-3.0`

# Libs
LIBS= -lsqlite3
GTKLIBS = `pkg-config --libs gtk+-3.0`

all: cli.o database.o
	${CC} ${CFLAGS} -o lms database.o cli.o ${LIBS}

main.o: main.c
	${CC} ${CFLAGS} ${GTKFLAGS}	-o $@ -c $< ${GTKLIBS}

gui.o: gui.c
	${CC} ${CFLAGS} ${GTKFLAGS}	-o $@ -c $< ${GTKLIBS}

cli.o: cli.c
	${CC} ${CFLAGS} -o $@ -c $<

database.o: database.c
	${CC} ${CFLAGS} -o $@ -c $<

run:
	./lms

clean:
	rm lms *.o
