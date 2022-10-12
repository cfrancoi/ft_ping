#ifndef __UTILS_H__
#define __UTILS_H__

unsigned short checksum(void *b, int len);
int            resolve_dns(const char *c_addr, struct in_addr *dst);

#include "options.h"
unsigned int get_packet_size(const t_options *opts);
void        *create_packet(int pid, int seq, int size, iphdr_t *ip);
void         print_stat(void);
void         free_memory(void);

#endif // __UTILS_H__