#include "icmphdr.h"
#include "iphdr.h"
#include "ping.h"
#include <stdio.h>

/**
 *
 */
void print_response(void *packet, int flags, ping_t *ret, struct timeval tv)
{
	if (flags)
		(void) flags;

	icmphdr_t *icmp;
	iphdr_t   *iphdr;

	iphdr = packet;
	icmp = packet + IP_HEADER_LEN;

	printf("Response: %u, code %u - seq %u, id: %u, ttl %u ", (icmp->type), (icmp->code), ntohs(icmp->seq), ntohs(icmp->id),
	       (iphdr->ip_ttl));
	if (ret != NULL)
		printf("Time : %.3f ms\n", (double) ((tv.tv_sec - ret->tv_send.tv_sec) * 1000 +
		                                     (double) (tv.tv_usec - ret->tv_send.tv_usec) / 1000));
}
