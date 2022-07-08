#ifndef OPTIONS_H
#define OPTIONS_H

#include <unistd.h>
//define flags

#define FLAG_H 0b1
#define FLAG_V 0b10
// Bonus
#define FLAG_4 0b100
#define FLAG_6 0b1000
#define FLAG_C 0b10000
#define FLAG_S 0b100000

#define FLAGS_LIST "hv46cs"

#define FLAG_NEED_PARAM (FLAG_C | FLAG_S)

//function utils

typedef struct	s_options
{
	int	flags;
	int	count;
	size_t	size;
}		t_options;


int 	get_flags(const char **s, t_options *opts);
int 	flag_need_param(int flag);

int	set_flags(const char **s, t_options *opts);



#endif
