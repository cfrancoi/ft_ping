#include <options.h>
#include "debug.h"

int set_flag_h()
{
	debug_print("Set flag H\n");
	return 0; 
}

static int(*g_func_flag[])(void) =
{
	set_flag_h //FLAG_H	
};

int	set_flags(const char *s, int flags)
{
	debug_print("Start set flags\n");
	(void)s;
	(void)g_func_flag[flags - 1]();
	return (0);
}
