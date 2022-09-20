#include "icmphdr.h"
#include "libft.h"

#include <stdio.h>

int recv_pckt(int size, void **packet, struct sockaddr_in *sin, int rcv_sock)
{

			struct sockaddr_in r_addr;

			ft_memset ((char *)&r_addr, 0, sizeof (struct sockaddr_in));
			socklen_t t = sizeof(struct sockaddr);
			
			//struct timeval tv_out;

			//tv_out.tv_sec = RECV_TIMEOUT;
			//tv_out.tv_usec = 0;

		  	//setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv_out, sizeof tv_out);
			//int rcv_sock = socket(AF_INET, SOCK_RAW, IP_PROTO_ICMP);
			if (recvfrom(rcv_sock, (void *)*packet, size, 0, (struct sockaddr *)sin, &t) <= 0)
			{
				perror("recvfrom()");
				return 1;
			}
			else
			{
				printf("Packet rcv\n");

				//iphdr_t *ip;
				icmphdr_t *icmp;

				icmp = *packet + IP_HEADER_LEN;

				//write(2, packet, packet_size);
				printf("Response: %u, code %u - seq %u, id: %u\n", (icmp->type), (icmp->code), ntohs(icmp->seq), ntohs(icmp->id));
			}
			return 0;

}