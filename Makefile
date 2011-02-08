CC = g++
CFLAGS = -g
LDFLAGS =

all: socketlistener

socketlistener: socketlistener.o
	$(CC) $(LDFLAGS) -o $@ $^

socketlistener.o: socketlistener.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -fr *.o
	rm socketlistener

# This is GNU makefile extension to notify that roughly means: 'clean' does
# not depend on any files in order to call it.
.PHONY: clean