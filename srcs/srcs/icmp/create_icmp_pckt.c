#include "iphdr.h"
#include "icmphdr.h"
#include <string.h>
#include <stdlib.h>


/*
	** Alloc and Fill a packet with ip_hdr, icmp_hdr and data	
	** returned packet need to be free after usage
*/
char	*create_icmp_pckt(iphdr_t *ip_hdr, icmphdr_t *icmp_header, char *data)
{
	size_t	len;

	len = IP_HEADER_LEN + ICMP_HEADER_LEN + strlen(data); //todo use libft

	char *pck = malloc(len);
	if (pck == NULL)
		return (NULL);
	// ADD ip header
	memcpy(pck, ip_hdr, IP_HEADER_LEN);

	//ADD icmp header
	memcpy(pck + IP_HEADER_LEN, icmp_header, ICMP_HEADER_LEN);

	//ADD data
	memcpy(pck + IP_HEADER_LEN + ICMP_HEADER_LEN, data, strlen(data));

	return (pck);
}