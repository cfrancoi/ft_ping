#include "options.h"
#include "debug.h"
#include "libft.h"

int set_flag_c(const char *c, t_options *opts, int flag)
{
	(void)set_simple_flag(c, opts, flag);

	opts->count = ft_atoi(c);
	
	debug_print("FLAG_C: %s\n", c);
	return (1);
}