#ifndef OPTIONS_H
#define OPTIONS_H

#include <unistd.h>
// define flags

#define FLAG_H 0b1
#define FLAG_V 0b10
// Bonus
#define FLAG_4 0b100     // use Ip v4
#define FLAG_6 0b1000    // use Ip v6
#define FLAG_C 0b10000   // count of ping
#define FLAG_S 0b100000  // packet size
#define FLAG_T 0b1000000 // ttl

#define FLAGS_LIST "hv46cst"

#define FLAG_NEED_PARAM (FLAG_C | FLAG_S | FLAG_T)
#define FLAGISSET(mask, flag) (mask & flag)

typedef struct s_options
{
	const char   *host;
	int           flags;
	int           count;
	unsigned char ttl;
	size_t        size;
} t_options;

#define DEFAULT_SIZE 56
#define DEFAULT_TTL 12
#define DEFAULT_COUNT -1

/**
 * Utils
 */
void add_mask(int *flags, int mask);
int  flag_need_param(int flag);
int  set_simple_flag(const char *, t_options *opts, int flag);

void init_t_options(t_options *opts);

/**
 * Function to set flags
 */
int set_flag_c(const char *, t_options *opts, int flag);
int set_flag_s(const char *, t_options *opts, int flag);
int set_flag_ttl(const char *, t_options *opts, int flag);
int set_flag_h(const char *c, t_options *opts, int flag);

int get_flags(const char **s, t_options *opts);
int set_flags(const char **s, size_t *i, size_t *j, t_options *opts);

#endif
