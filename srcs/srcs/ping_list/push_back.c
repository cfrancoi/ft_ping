#include "ping.h"


/**
 * Add *new to given head
 */
void push_back(ping_t **head, ping_t *new)
{
	ping_t *tmp;

	tmp = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}