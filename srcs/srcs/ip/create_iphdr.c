#include "iphdr.h"
#include "utils.h"

#include <arpa/inet.h>
#include <stdio.h>

int create_iphdr(int packet_size, u_char ttl, const char *to, iphdr_t *dst_ip)
{
	iphdr_t			ip;

	struct in_addr dst, src;

	if (inet_pton(AF_INET, to, &dst) < 0)
	{
		perror("inet_pton()");
		return 1;
	} // dest ip_v4 addr (AF_INET)
	if (inet_pton(AF_INET, "0.0.0.0", &src) < 0) // src ip_v4 addr (AF_INET) //todo
	{
		perror("inet_pton()");
		return 1;
	} // dest ip_v4 addr (AF_INET)

	if (resolve_dns(to, &dst) != 0)
	{
		perror("resolve_dns()");
		return 1;
	}


	char ip_dst[42];
	(void)inet_ntop(AF_INET, &dst, (char *)&ip_dst, sizeof(ip_dst));
	ip_dst[41] = '\0';
	//debug_print("ICMP_HDR_LEN : %u\n", ICMP_HEADER_LEN);

	struct in_addr ips[2];

	ips[0] = src;
	ips[1] = dst;
	init_iphdr(&ip, packet_size, ttl, ips);
	ip.ip_sum = checksum(&ip, IP_HEADER_LEN);

	*dst_ip = ip;
	return 0;
}