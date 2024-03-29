#include "debug.h"
#include "options.h"
#include "ping.h"
#include <stdio.h>

ping_data_t g_ping_data = {0};

int main(int ac, const char **av)
{
	int ret;

	debug_print("FT_PING: start program\n");
	(void) ac;
	(void) av;

	if (ac > 1)
	{
		ret = get_flags((const char **) &av[1], &g_ping_data.opts);
		if (ret == 0)
		{
			debug_print("FT_PING: can be start !\n");
			init_routine();
			start_routine();
			stop_routine();
		}
	}

	return (0);
}
