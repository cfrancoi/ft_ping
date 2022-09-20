#include <sys/socket.h>
#include <stdio.h>

int send_pckt(int sock, const void *packet, size_t size, void *sin)
{
	if (sendto(sock, (const void *)packet, size, 0, (const struct sockaddr *)sin, sizeof(struct sockaddr)) <= 0)
	{
		perror("sendto()");
		return 1;
	}
	else
	{
		printf("Packet send\n");
	}

	return (0);
}