#include "ping.h"

void	clear_all(ping_t *head)
{
	ping_t	*tmp;

	tmp = head;

	while (head)
	{
		tmp = head->next;
		
		clear_one(head);
		head = tmp;
	}
};