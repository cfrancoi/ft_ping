#include "options.h"

int set_flag_s(const char *c, t_options *opts, int flag)
{
	(void)set_simple_flag(c, opts, flag);

	return (1);
}