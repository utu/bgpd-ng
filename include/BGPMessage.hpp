#ifndef BGPMESSAGE_HPP_
#define BGPMESSAGE_HPP_

static int MESSAGE_TYPE_OPEN = 1;
static int MESSAGE_TYPE_UPDATE = 2;
static int MESSAGE_TYPE_NOTIFICATION = 3;
static int MESSAGE_TYPE_KEEPALIVE = 4;
static int MESSAGE_TYPE_ROUTEREFRESH = 5;

class BGPMessage {
	BGPMessage(const char* message);
	int messageType();
private:

};
#endif
