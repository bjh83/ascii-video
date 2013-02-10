SHELL= /bin/sh
PACKAGE= asciivideo
VERSION= 0.1
OBJS= main.o image.o framewriter.o
CC= g++

.PHONY: all

all: $(PACKAGE)

$(PACKAGE): $(OBJS)
	$(CC) -o $(PACKAGE) $(OBJS) `pkg-config --libs opencv ncurses` -lboost_thread

main.o: image.h

image.o: image.h

framewriter.o: image.h framewriter.h

.PHONY: clean

clean:
	rm -rf $(OBJS) $(PACKAGE)

