#include "options.h"
#include "debug.h"

int set_simple_flag(const char *c, t_options *opts, int flag)
{
	debug_print("Set flag %c\n", flag);
	//debug_print("Set flag \n");
	(void)c;
	add_mask(&opts->flags, flag);
	
	return (1); 
}