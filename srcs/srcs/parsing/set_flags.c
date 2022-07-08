#include <cstddef>
#include <options.h>
#include "debug.h"

static int	ft_strchr_index(const char *s, const int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

int set_flag_h()
{
	debug_print("Set flag H\n");
	return 0; 
}

static int(*g_func_flag[])(const char *, t_options *opts) =
{
	set_flag_h //FLAG_H	
};

int	set_flags(const char **s, size_t *i, size_t *j, t_options *opts)
{	
	int n;
	int flag;

	n = 0;
	while (s[*i][*j])
	{
		n = ft_strchr_index(FLAGS_LIST, (const int)s[i]);
		//TODO return usage FLAG_H
		if (n == -1)	
			return (0);
		flag = (1 << n);
		debug_print("PARS: %c param: %i\n", s[i], flag_need_param(flag);
		if (flag_need_param(flag))
		{
			if (s[*i][*j])
			{

			}
			else if (++i, s[i] != NULL)
			{

			}
			else
			{
				return (0)
			}

		}
	}
	return (0);
}
