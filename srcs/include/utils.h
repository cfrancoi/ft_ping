#ifndef __UTILS_H__
#define __UTILS_H__

unsigned short	checksum(void *b, int len);
int				resolve_dns(const char *c_addr, struct in_addr *dst);

#endif // __UTILS_H__