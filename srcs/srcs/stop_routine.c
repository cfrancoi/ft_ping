#include "utils.h"

/**
 *	Function to stop ping context (when routine is starting)
 *	free memory and print recap
 */
int stop_routine(void)
{
	print_stats();
	free_memory();
	return (0);
}