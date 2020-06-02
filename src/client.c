#include "../h/common.h"

int main(int argc, char **argv) {
	uint16_t port;
	char *host;
	int sockfd;
	struct sockaddr_in saddr;
	char buff[BUFF_LEN+1];

	printf("Starting Client\n");
	if (argc != 3) {
		Exit_With_Error("Usage client.x [port_number] [host_address]");
	}

	port = Check_Port(argv[1]);

	if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) { // create_socket
		Exit_With_Error("Socket Error");
	}
	printf("Created socket successfully\n");
	host = argv[2];
	memset(&saddr, 0, sizeof(saddr));
	int host_n = inet_aton(host, &saddr.sin_addr);
	if (host_n < 0) {//error if host_n < 0
		Exit_With_Error("Host Address Error");
	}


	saddr.sin_family = AF_INET;
	saddr.sin_port = htobe16(port);
	printf("Prepared server address\n");
	//active open
	if (connect(sockfd, (struct sockaddr *)&saddr, sizeof(saddr)) < 0) { // error in connection
		Exit_With_Error("Connect Error");
	}
	printf("Connected to server\n");
	
	int n, len;
	printf(">> Send to server: ");
	while (fgets(buff, sizeof(buff), stdin)) {
		len = strlen(buff);
		buff[len] = 0;
		n = send(sockfd, buff, len, 0);
		if (!n) {
			Exit_With_Error("Error sending\n");

		}
		printf("Sent %d bytes\n", n);
		printf("\nSend to server: ");
	}
	

	close(sockfd);
	printf("Disconnected from server\n");
	return 0;
}

