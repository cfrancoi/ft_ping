#include "ping.h"
#include "iphdr.h"
#include "icmphdr.h"
#include "debug.h"

int init_routine(void)
{
	debug_print("FT_PING: can be start !\n");
	iphdr_t iphdr;

	create_iphdr(DEFAULT_SIZE, g_ping_data.opts.ttl, g_ping_data.opts.host, &iphdr);


	//create socket;

	//todo signal alarm 
	start_routine(&iphdr);

	return (0);
}