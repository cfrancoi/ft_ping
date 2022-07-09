#include "options.h"
#include "debug.h"

int set_flag_c(const char *c, t_options *opts, int flag)
{
	(void)set_simple_flag(c, opts, flag);
	debug_print("FLAG_C: %s\n", c);
	return (1);
}