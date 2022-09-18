#include "ping.h"
#include "iphdr.h"
#include "debug.h"

int init_routine(void)
{
	debug_print("FT_PING: can be start !\n");
	iphdr_t iphdr;

	create_iphdr(DEFAULT_SIZE, g_ping_data.opts.host, &iphdr);

	

	return (0);
}