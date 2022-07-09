#include "options.h"
#include <stdio.h>

static void print_usage(void)
{
	fprintf(stdout, "Usage:\nTodo\n");
}

int set_flag_h(const char *c, t_options *opts, int flag)
{
	(void)set_simple_flag(c, opts, flag);

	print_usage();

	return (2);
}