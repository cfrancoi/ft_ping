#include "icmphdr.h"
#include "libft.h"

#include <stdio.h>
#include <sys/time.h>

#include "ping.h"
#include "utils.h"
/**
 * utils function to get ping from seq value
 */
static ping_t *get_one(uint16_t seq, ping_t *head)
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

	ft_memset((char *) &r_addr, 0, sizeof(struct sockaddr_in));
	socklen_t t = sizeof(struct sockaddr);

	struct timeval tv;
	if (recvfrom(rcv_sock, (void *) *packet, size, 0, (struct sockaddr *) sin, &t) <= 0)
	{
		perror("recvfrom()");
		return 1;
	}
	else
	{
		gettimeofday(&tv, NULL);

		icmphdr_t *icmp;

		icmp = *packet + IP_HEADER_LEN;
		int seq;

		seq = ntohs(icmp->seq);

		ping_t *ret = get_one(seq, g_ping_data.pings); // TODO if i'm null

		print_response(*packet, g_ping_data.opts.flags, ret, tv);
	}
	return 0;
}