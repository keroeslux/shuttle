CC := gcc
CFLAGS := -Wall -O2 
NAME := shuttle-conf
FILES := src/source/*
OFILES := parse.o colors.o log.o shuttle-conf.o extra_functions.o handle_setup.o


install:
	$(CC) -c $(FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES) 
	rm -rf $(OFILES)

clean:
	rm -rf $(OFILES)

copy:
	cp $(OFILES) src/
