#include "iphdr.h"
#include "icmphdr.h"
#include "utils.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

void		*create_packet(int pid, int seq, int size, iphdr_t *ip)
{
	icmphdr_t	icmp;

	init_icmphdr(&icmp, pid, seq);
	printf("ICMP Header init \n");

	//write(2, &icmp, ICMP_HEADER_LEN);

	/*char		data[PACKET_SIZE + 1] = { 1, 2, 3, 4, 0};

	//memset(data, 1, PACKET_SIZE);
	data[PACKET_SIZE] = 0;*/

	char		*data = malloc(size + 1);
	memset(data, 1, size);
	char		*packet;

	packet = create_icmp_pckt(ip, &icmp, data);
	data[size] = 0;

	icmp.checksum = checksum(packet + IP_HEADER_LEN, size - IP_HEADER_LEN);
	free(packet);

	packet = create_icmp_pckt(ip, &icmp, data);
	data[size] = 0;

	free(data);

	return (packet);
}
	
	