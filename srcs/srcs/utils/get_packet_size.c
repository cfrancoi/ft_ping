#include "icmphdr.h"
#include "iphdr.h"
#include "options.h"
#include <stdint.h>

unsigned int get_packet_size(const t_options *opts)
{
	uint16_t iphdr_len;
	uint16_t icmphdr_len;
	uint16_t data_len;

	data_len = opts->size;

	if (FLAGISSET(opts->flags, FLAG_6))
	{
		// fix me use V6 value
		iphdr_len = IP_HEADER_LEN;
		icmphdr_len = ICMP_HEADER_LEN;
	}
	else
	{
		iphdr_len = IP_HEADER_LEN;
		icmphdr_len = ICMP_HEADER_LEN;
	}

	return (iphdr_len + icmphdr_len + data_len);
}