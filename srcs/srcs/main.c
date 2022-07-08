#include <stdio.h>
#include "debug.h"
#include "options.h"

int main(int ac, char **av)
{
	
	t_options opts;

	debug_print("FT_PING: start program\n");	
	(void)ac;
	(void)av;


	if (av[1])
		(void)get_flags(av[1], NULL);	

	return (0);	
}
