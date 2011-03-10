CC = g++
CFLAGS = -g -I/opt/local/include -O0 -Wall
LDFLAGS = -L/opt/local/lib -lboost_thread-mt -lboost_regex -lboost_program_options -lboost_system

all: bgpd-ng bgp-fsm

bgpd-ng: main.o SocketExample.o Socket.o ServerSocket.o
	$(CC) $(LDFLAGS) -o $@ $^

main.o: main.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

SocketExample.o: SocketExample.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

Socket.o: Socket.cpp
	$(CC) $(CFLAGS) -c -o $@ $<
	
ServerSocket.o: ServerSocket.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

bgp-fsm: BGP_FSM.o BGP_Functions.o BGP_Timer.o BGP_State.o
	$(CC) $(LDFLAGS) -o $@ $^

BGP_FSM.o: BGP_FSM.cpp
	$(CC) $(CFLAGS) -c -o $@ $<
	
BGP_State.o: BGP_State.cpp	
	$(CC) $(CFLAGS) -c -o $@ $<
	
BGP_Functions.o: BGP_Functions.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

BGP_Timer.o: BGP_Timer.cpp
	$(CC) $(CFLAGS) -c -o $@ $<	

clean:
	rm -fr *.o
	rm bgpd-ng
	rm bgp-fsm

# This is GNU makefile extension to notify that roughly means: 'clean' does
# not depend on any files in order to call it.
.PHONY: clean
