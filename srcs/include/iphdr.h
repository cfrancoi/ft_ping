#ifndef __IPHDR_H__
#define __IPHDR_H__
#include <netinet/in.h>
#include <stdint.h>

/*
 * //todo IP_PACKET_MAX_LEN
 */

typedef struct iphdr_s
{
	uint8_t ip_hl : 4, /* header length */
	    ip_v : 4;      /* version */

	uint8_t  ip_tos; /* type of service */
	uint16_t ip_len; /* total len */
	uint16_t ip_id;  /* identification */
	uint16_t ip_off; /* offset */

	uint8_t  ip_ttl; /* time to live */
	uint8_t  ip_pro; /*  protocol */
	uint16_t ip_sum;

	struct in_addr ip_src, ip_dst;
} iphdr_t;

#define IP_HEADER_LEN sizeof(iphdr_t)
//#define IP_HEADER_HL IP_HEADER_LEN / 5
#define IP_PROTO_ICMP 1

void init_iphdr(iphdr_t *hdr, uint16_t len, uint8_t ttl, struct in_addr ip[2]);
int create_iphdr(int packet_size, uint8_t ttl, const char *to, iphdr_t *dst_ip);

#endif // __IPHDR_H__