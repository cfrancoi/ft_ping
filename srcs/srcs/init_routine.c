#include "ping.h"
#include "iphdr.h"
#include "icmphdr.h"
#include "debug.h"


//todo v6 & v4
#include "libft.h"
static struct sockaddr_in  init_sockaddr_in(iphdr_t *iphdr)
{
		struct sockaddr_in sin;

		ft_memset ((char *)&sin, 0, sizeof (struct sockaddr_in));
		sin.sin_family = AF_INET;
		sin.sin_addr.s_addr = iphdr->ip_dst.s_addr;

		return sin;
}

int init_routine(void)
{
	debug_print("FT_PING: can be start !\n");
	iphdr_t iphdr;
	const int on = 1;

	create_iphdr(DEFAULT_SIZE, g_ping_data.opts.ttl, g_ping_data.opts.host, &iphdr);


	//create socket;
	g_ping_data.send		= 0;
	g_ping_data.pings		= NULL;
	g_ping_data.sin			= init_sockaddr_in(&iphdr);
	g_ping_data.send_sock	= socket(AF_INET, SOCK_RAW, IPPROTO_RAW); //fix check error
	setsockopt(g_ping_data.send_sock, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)); //fix check error


	g_ping_data.rcv_sock	= socket(AF_INET, SOCK_RAW, IP_PROTO_ICMP); //fix check error
	
	
	//todo signal alarm 
	start_routine(&iphdr);

	return (0);
}