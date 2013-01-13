SHELL= /bin/sh
PACKAGE= asciivideo
VERSION= 0.1
OBJS= main.o image.o framewriter.o
CC= g++

.PHONY: all

all: $(PACKAGE)

$(PACKAGE): $(OBJS)
	$(CC) -o $(PACKAGE) $(OBJS) `pkg-config --libs opencv ncurses`

.PHONY: clean

clean:
	rm -rf $(OBJS) $(PACKAGE)

