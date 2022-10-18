#include "icmphdr.h"
#include "iphdr.h"
#include "ping.h"
#include "utils.h"
#include <stdlib.h>

// fix remove include

#include <stdio.h>
#include <string.h>

#include <signal.h>
#include <unistd.h>

#include "ping.h"
#include <sys/time.h>

#include "debug.h"

/**
 *	Routine for alarm send ping with g_ping's data and resend alarm
 */
void sig_handler_alarm(int sig)
{
	void	      *packet;
	iphdr_t        iphdr;
	struct timeval tv;
	(void) sig;

	if (g_ping_data.send != g_ping_data.opts.count)
	{
		create_iphdr(DEFAULT_SIZE, g_ping_data.opts.ttl, g_ping_data.opts.host, &iphdr);
		packet = create_packet(getpid(), g_ping_data.send, g_ping_data.opts.size, &iphdr);

		ping_t *data;
		{
			data = malloc(sizeof(ping_t));

			gettimeofday(&tv, NULL);
			data->next = NULL;
			data->seq = g_ping_data.send;
			data->tv_send = tv;
		}
		push_back(&g_ping_data.pings, data);

		send_pckt(g_ping_data.send_sock, packet, g_ping_data.opts.size,
		          &g_ping_data.sin);

		free(packet);
		g_ping_data.send++;
		alarm(1);
	}
	// return 0;
}

/**
 * Launch send's routine and wait to rcv next ping
 */
int start_routine(void)
{
	int   seq;
	void *packet;

	seq = 0;
	signal(SIGALRM, &sig_handler_alarm);
	alarm(1);
	while (g_ping_data.recv != g_ping_data.opts.count)
	{
		// create_packet
		packet =
		    create_packet(getpid(), seq, g_ping_data.opts.size, &g_ping_data.iphdr);

		recv_pckt(g_ping_data.opts.size, &packet, &g_ping_data.sin, g_ping_data.rcv_sock);

		free(packet);
		g_ping_data.recv++;

		// return (0);
	}

	return (0);
}