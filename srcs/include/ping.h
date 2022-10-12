#ifndef __PING_H__
#define __PING_H__

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "iphdr.h"
#include "options.h"
#include <sys/time.h>

/**
 * struct for list of emited pings
 */
typedef struct ping_s
{
	uint16_t       seq;
	struct timeval tv_send;

	struct ping_s *next;
} ping_t;

typedef struct ping_data_s
{
	struct sockaddr_in sin;   /* dest's socket addr */
	ping_t	        *pings; /* list of pings emited */
	t_options          opts;  /* list of options set */
	uint16_t           send;  /* nu of emited */
	uint16_t           recv;  /* nu of receved */
	int                rcv_sock;
	int                send_sock;
} ping_data_t;

extern ping_data_t g_ping_data;

// g_ping_data = {0};

void push_back(ping_t **head, ping_t *to_add);

void clear_one(ping_t *data);
void clear_all(ping_t **head);
/**
 * MAIN FUNCTION
 */
int init_routine(void);
int start_routine(iphdr_t *iphdr);
int stop_routine(void);
int recv_pckt(int size, void **packet, struct sockaddr_in *sin, int rcv_sock);
int send_pckt(int sock, void *packet, size_t size, void *sin);

#endif // __PING_H__