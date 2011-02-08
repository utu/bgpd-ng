CC = g++
CFLAGS = -g -I/opt/local/include -O0 -Wall
LDFLAGS = -L/opt/local/lib

all: bgpd-ng

bgpd-ng: main.o SocketListener.o Socket.o ServerSocket.o
	$(CC) $(LDFLAGS) -o $@ $^

main.o: main.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

SocketListener.o: SocketListener.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

Socket.o: Socket.cpp
	$(CC) $(CFLAGS) -c -o $@ $<
	
ServerSocket.o: ServerSocket.cpp
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -fr *.o
	rm bgpd-ng

# This is GNU makefile extension to notify that roughly means: 'clean' does
# not depend on any files in order to call it.
.PHONY: clean
