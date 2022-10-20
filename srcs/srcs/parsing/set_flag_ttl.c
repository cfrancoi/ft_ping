#include "debug.h"
#include "libft.h"
#include "options.h"

int set_flag_ttl(const char *c, t_options *opts, int flag)
{
	(void) set_simple_flag(c, opts, flag);

	opts->ttl = ft_atoi(c);

	debug_print("FLAG_T: %i\n", opts->ttl);
	return (1);
}