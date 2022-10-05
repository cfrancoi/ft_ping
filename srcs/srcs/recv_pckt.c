#include "icmphdr.h"
#include "libft.h"

#include <stdio.h>
#include <sys/time.h>



#include "ping.h"
/**
 * utils function to get ping from seq value
 */
static ping_t		*get_one(uint16_t seq, ping_t *head)
{
	while (head)
	{
		if (head->seq == seq)
			return head;

		head = head->next;
	}

	return (NULL);
}

int recv_pckt(int size, void **packet, struct sockaddr_in *sin, int rcv_sock)
{
			struct sockaddr_in r_addr;

			ft_memset ((char *)&r_addr, 0, sizeof (struct sockaddr_in));
			socklen_t t = sizeof(struct sockaddr);
			
			struct timeval	tv;
			if (recvfrom(rcv_sock, (void *)*packet, size, 0, (struct sockaddr *)sin, &t) <= 0)
			{
				perror("recvfrom()");
				return 1;
			}
			else
			{
				gettimeofday(&tv, NULL);

				icmphdr_t 	*icmp;
				iphdr_t		*iphdr;

				iphdr = *packet;
				icmp = *packet + IP_HEADER_LEN;
				int seq;
				

				
				seq = ntohs(icmp->seq);

				ping_t *ret = get_one(seq, g_ping_data.pings);

				printf("Response: %u, code %u - seq %u, id: %u, ttl %u\n", (icmp->type), (icmp->code), ntohs(icmp->seq), ntohs(icmp->id), (iphdr->ip_ttl));
				if (ret != NULL)
					printf("Time : %.3f ms\n", (double)((tv.tv_sec - ret->tv_send.tv_sec) * 1000 +  (double)(tv.tv_usec - ret->tv_send.tv_usec) / 1000));
			}
			return 0;

}