#include <netinet/ip.h>
#include "iphdr.h"
#include <unistd.h>

void	init_iphdr(iphdr_t *hdr, uint16_t len, u_char ttl, struct in_addr ip[2])
{
	hdr->ip_v  = 4;
	hdr->ip_hl = 5; //TODO CREATE DEFINE 

	hdr->ip_tos = 0;
	hdr->ip_len = htons(len);
	hdr->ip_id	= htons (getpid());;

	hdr->ip_ttl = (uint8_t)ttl;
	hdr->ip_pro = IP_PROTO_ICMP;

	hdr->ip_sum = 0;

	hdr->ip_src = ip[0];
	hdr->ip_dst = ip[1];
}