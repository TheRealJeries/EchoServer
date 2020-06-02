#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <endian.h>
#include <string.h>


#ifndef MAX_PORT
#define MAX_PORT 65536
#endif

void Exit_With_Error(char *);
uint16_t Check_Port(char *);
#endif 
