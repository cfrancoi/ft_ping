#ifndef __UTILS_H__
#define __UTILS_H__
#include "iphdr.h"

unsigned short checksum(void *b, int len);
int            resolve_dns(const char *c_addr, struct in_addr *dst);

#include "options.h"
unsigned int get_packet_size(const t_options *opts);
void        *create_packet(int pid, int seq, int size, iphdr_t *ip);
void         print_stats(void);
void         free_memory(void);

#include "ping.h"
void print_response(void *packet, int flags, ping_t *ping, struct timeval tv);

#endif // __UTILS_H__