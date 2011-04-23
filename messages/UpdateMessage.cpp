#include "message/UpdateMessage.hpp"

UpdateMessage::UpdateMessage() {

}

/*
 *		 This variable length field contains a list of IP address
         prefixes.  The length, in octets, of the Network Layer
         Reachability Information is not encoded explicitly, but can be
         calculated as:

               UPDATE message Length - 23 - Total Path Attributes Length
               - Withdrawn Routes Length

         where UPDATE message Length is the value encoded in the fixed-
         size BGP header, Total Path Attribute Length, and Withdrawn
         Routes Length are the values encoded in the variable part of
         the UPDATE message, and 23 is a combined length of the fixed-
         size BGP header, the Total Path Attribute Length field, and the
         Withdrawn Routes Length field.
 */
__uint16_t UpdateMessage::reachabilityLength() {
	return 0;
}
