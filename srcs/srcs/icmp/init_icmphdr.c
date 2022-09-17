
#include "icmphdr.h"

void	init_icmphdr(icmphdr_t *hdr, uint16_t id, uint16_t seq)
{
	hdr->type = ICMP_TYPE_ECHOREQ; // Type
	hdr->code = ICMP_CODE_ECHOREQ; // Code
	hdr->checksum = 0; // Checksum
	hdr->id = htons(id); // Identification
	hdr->seq = htons(seq); // Sequence
};

