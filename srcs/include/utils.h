#ifndef __UTILS_H__
#define __UTILS_H__

unsigned short	checksum(void *b, int len);
int				resolve_dns(const char *c_addr, struct in_addr *dst);

#include		"options.h"
unsigned int	get_packet_size(const t_options *opts);

#endif // __UTILS_H__