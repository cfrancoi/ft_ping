#include "libft.h"
#include "options.h"

/**
 * init opts with default value
 */
void init_t_options(t_options *opts)
{
	bzero(opts, sizeof(t_options));

	opts->size = DEFAULT_SIZE;
	opts->count = DEFAULT_COUNT;
	opts->ttl = DEFAULT_TTL;
	return;
}