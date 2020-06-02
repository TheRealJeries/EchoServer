#include "../h/client.h"

int main(int argc, char **argv) {
	long port; // ports are 16 bits, but need to be long to debug using strtol
	char *endptr; // for strtol debugging
	char *host;
	int sockfd;
	struct sockaddr_in saddr;

	printf("Starting Client\n");
	if (argc != 3) {
		Exit_With_Error("Usage client.x [port_number] [host_address]");
	}

	port = strtol(argv[1], &endptr, 10);
	host = argv[2];
	if (endptr[0] != 0 || port < 1 || port > MAX_PORT) {
		Exit_With_Error("Invalid Port Number, Must be between 1 and 65536");
	}

	if ((sockfd = socket(PF_INET, SOCK_STREAM, 0) < 0)) { // create_socket
		Exit_With_Error("Socket Error");
	}

	memset(&saddr, 0, sizeof(saddr));
	int host_n = inet_aton(host, &saddr.sin_addr);
	if (host_n < 0) {//error if host_n < 0
		Exit_With_Error("Host Address Error");
	}


	saddr.sin_family = AF_INET;
	saddr.sin_port = htobe16(port);


	if (connect(sockfd, (struct sockaddr *)&saddr, sizeof(saddr) < 0)) { // error in connection
		Exit_With_Error("Connect Error");
	}




	return 0;
}

void Exit_With_Error(char *msg) {
	perror(msg);
	exit(1);
}
