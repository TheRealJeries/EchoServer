#include "../h/common.h"

int main(int argc, char **argv) {
	struct sockaddr_in saddr;
	int sockfd, csock;
	uint16_t port;	
	if (argc != 2) {
		Exit_With_Error("Usage: server [port_number]");
	}

	port = Check_Port(argv[1]);
	
	memset(&saddr, 0, sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = INADDR_ANY;
	saddr.sin_port = htobe16(port);

	return 0;
}
