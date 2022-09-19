#include "ping.h"
#include "icmphdr.h"
#include "iphdr.h"
#include "utils.h"
#include <stdlib.h>


//fix remove include

#include <string.h>
#include <stdio.h>


int		start_routine(iphdr_t *iphdr)
{
	int			seq;
	void		*packet;

	seq = 0;

	while (seq != g_ping_data.opts.count)
	{
			//create_packet
			packet = create_packet(getpid(), seq, g_ping_data.opts.size, iphdr);

			//send ping


			{


			struct sockaddr_in sin;

			memset ((char *)&sin, 0, sizeof (struct sockaddr_in));
			sin.sin_family = AF_INET;
			sin.sin_addr.s_addr = iphdr->ip_dst.s_addr;

			int sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
			if (sock < 0)
			{
				perror("socket()");
				return 1;
			}

			

			const int on = 1;
			  if (setsockopt (sock, IPPROTO_IP, IP_HDRINCL, &on, sizeof (on)) < 0) {
			    perror ("setsockopt() failed to set IP_HDRINCL ");
			    return 1;
			  }


			if (sendto(sock, (const void *)packet, g_ping_data.opts.size, 0, (const struct sockaddr *)&sin, sizeof(struct sockaddr)) <= 0)
			{
				perror("sendto()");
				return 1;
			}
			else
			{
				printf("Packet send\n");
			}

			struct sockaddr_in r_addr;

			memset ((char *)&r_addr, 0, sizeof (struct sockaddr_in));
			socklen_t t = sizeof(struct sockaddr);
			
			//struct timeval tv_out;

			//tv_out.tv_sec = RECV_TIMEOUT;
			//tv_out.tv_usec = 0;

		   //setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv_out, sizeof tv_out);
			int rcv_sock = socket(AF_INET, SOCK_RAW, IP_PROTO_ICMP);
			if (recvfrom(rcv_sock, (void *)packet, g_ping_data.opts.size, 0, (struct sockaddr *)&sin, &t) <= 0)
			{
				perror("recvfrom()");
				return 1;
			}
			else
			{
				printf("Packet rcv\n");

				//iphdr_t *ip;
				icmphdr_t *icmp;

				icmp = packet + IP_HEADER_LEN;

				//write(2, packet, packet_size);
				printf("Response: %u, code %u - seq %u, id: %u\n", (icmp->type), (icmp->code), ntohs(icmp->seq), ntohs(icmp->id));
			}


			}

			free(packet);
			seq++;

			return (0);
	}

	return (0);
}