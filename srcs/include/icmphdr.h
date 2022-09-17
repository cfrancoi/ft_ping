#ifndef __ICMPHDR_H__
#define __ICMPHDR_H__
#include <stdint.h>
#include "iphdr.h"

typedef struct icmphdr_s
{
	uint8_t		type; // Type
	uint8_t		code; // Code
	uint16_t	checksum; // Checksum
	uint16_t	id; // Identification
	uint16_t	seq; // Sequence
}				icmphdr_t;

#define ICMP_HEADER_LEN sizeof(icmphdr_t)

#define ICMP_TYPE_ECHOREQ 8
#define ICMP_CODE_ECHOREQ 0

void	init_icmphdr(icmphdr_t *hdr, uint16_t id, uint16_t seq);
char	*create_icmp_pckt(iphdr_t *ip_hdr, icmphdr_t *icmp_header, char *data);

#endif // __ICMPHDR_H__