CC = g++
CFLAGS = -g -I/opt/local/include -O0 -Wall
LDFLAGS = -L/opt/local/lib -lboost_thread-mt -lboost_regex -lboost_program_options -lboost_system
OBJECTS=$(SOURCES:.cpp=.o)

all: bgpd-ng 

bgpd-ng: BGP_FSM.o BGP_Functions.o BGP_State.o BGP_Timer.o IpRoute2.o RouteWorker.o RoutingTable.o ServerSocket.o Socket.o SocketExample.o main.o
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<	

clean:
	rm -fr *.o
	rm bgpd-ng

# This is GNU makefile extension to notify that roughly means: 'clean' does
# not depend on any files in order to call it.
.PHONY: clean

