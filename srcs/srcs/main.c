#include <stdio.h>
#include "debug.h"
#include "options.h"

int main(int ac, const char **av)
{
	t_options	opts;
	int			ret;

	debug_print("FT_PING: start program\n");	
	(void)ac;
	(void)av;


	if (ac > 1)
	{
		ret = get_flags((const char **)&av[1], &opts);
		if (ret == 0)
		{
			debug_print("FT_PING: can be start !\n");
		}
	}

	return (0);	
}
