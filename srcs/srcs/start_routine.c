#include "ping.h"
#include "icmphdr.h"
#include "iphdr.h"
#include "utils.h"
#include <stdlib.h>


//fix remove include

#include <string.h>
#include <stdio.h>


int		start_routine(iphdr_t *iphdr)
{
	int			seq;
	void		*packet;

	seq = 0;

	while (seq != g_ping_data.opts.count)
	{
			//create_packet
			packet = create_packet(getpid(), seq, g_ping_data.opts.size, iphdr);

			//send ping
			if (sendto(g_ping_data.send_sock, (const void *)packet, g_ping_data.opts.size, 0, (const struct sockaddr *)&g_ping_data.sin, sizeof(struct sockaddr)) <= 0)
			{
				perror("sendto()");
				return 1;
			}
			else
			{
				printf("Packet send\n");
			}
				recv_pckt(g_ping_data.opts.size, &packet, &g_ping_data.sin, g_ping_data.rcv_sock);

			free(packet);
			seq++;

			//return (0);
	}

	return (0);
}