CC := gcc
CFLAGS := -Wall -O2 
NAME := shuttle-conf
FILES := src/source/parse.c src/source/colors.c src/source/log.c src/source/shuttle-conf.c src/source/extra_functions.c src/source/handle_setup.c
OFILES := parse.o colors.o log.o shuttle-conf.o extra_functions.o handle_setup.o

default:
	$(CC) -c $(FILES)

install:
	$(CC) $(CFLAGS) -o src/$(NAME) $(OFILES)

clean:
	rm -rf $(OFILES)

copy:
	cp $(OFILES) src/
