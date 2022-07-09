#include "options.h"

void 	add_mask(int *flags, int mask)
{
	*flags = mask | *flags;
}