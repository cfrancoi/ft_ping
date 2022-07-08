#include "options.h"

int 	flag_need_param(int flag)
{
	if (FLAG_NEED_PARAM & flag)
		return (1);
	return (0);
}
