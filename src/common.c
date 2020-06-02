#include "../h/common.h"

void Exit_With_Error(char *msg) {
	perror(msg);
	exit(-1);
}

uint16_t Check_Port(char *port_s) {
	char *endptr;
	long port = strtol(port_s, &endptr, 10);
	if (endptr[0] != 0 || port < 1 || port > MAX_PORT) {
		Exit_With_Error("Invalid Port Number, Must be between 1 and 65536");
	}
	return (uint16_t)port;
}
