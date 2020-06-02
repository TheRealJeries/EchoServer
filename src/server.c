#include "../h/common.h"

int main(int argc, char **argv) {
	struct sockaddr_in saddr;
	int sockfd, csock;
       	socklen_t len;
	uint16_t port;	
	char buff[BUFF_LEN+1];
	if (argc != 2) {
		Exit_With_Error("Usage: server [port_number]");
	}

	port = Check_Port(argv[1]);
	
	memset(&saddr, 0, sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = INADDR_ANY;
	saddr.sin_port = htobe16(port);

	// create socket accepting connections
	if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
		Exit_With_Error("Socket Error");
	}
	printf("Socket created successfully\n");
	// assign a name to the socket
	if (bind(sockfd, (struct sockaddr *)&saddr, sizeof(saddr)) < 0) {
		Exit_With_Error("Bind Error");
	}
	printf("Assigned socket name\n");
	// listen to incoming connections, Passive Open
	if (listen(sockfd, 128) < 0) {
		Exit_With_Error("Listen Error");
	}
	printf("Listening to incoming connections\n");

	while (1) {
		if ((csock = accept(sockfd, (struct sockaddr *)&saddr,
				       	&len)) < 0) {
			Exit_With_Error("Accept Error");
		}
		printf("Connection established\n");
		while ((len = recv(csock, buff, sizeof(buff), 0))) {
			if (len < 0) {
				Exit_With_Error("Recv Error");
			}
			if (len > BUFF_LEN) {
				printf("Buffer overflow\n");
				break;
			}
			printf("Client says [%d bytes]:", len); 
			fputs(buff, stdout);
		}
		close(csock);
		printf("Connection destroyed\n");
	}

	return 0;
}
