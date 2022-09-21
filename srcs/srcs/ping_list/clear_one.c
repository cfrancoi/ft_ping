#include "ping.h"
#include <stdlib.h>

void	clear_one(ping_t *data)
{
	free(data);
}