#include "options.h"
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


static int(*g_func_flag[])(const char *, t_options *opts, int flag) =
{
	set_flag_h,			//FLAG_H
	set_simple_flag,	//FLAG_V
	set_simple_flag,	//FLAG_4
	set_simple_flag,	//FLAG_6
	set_flag_c,			//FLAG_C
	set_flag_s			//FLAG_S
};


/**
 * 	return:
 * 	-1 : exit with err
 * 	0  : ok
 * 	1  : next av
 *  2  : exit without err
 */
int	set_flags(const char **s, size_t *i, size_t *j, t_options *opts)
{	
	int n;
	int flag;
	int ret;

	n = 0;
	ret = 0;
	debug_print("FT_PING: set flags\n");
	while (s[*i] && s[*i][*j])
	{
		n = ft_strchr_index(FLAGS_LIST, (const int)s[*i][*j]);
		if (n == -1)	
			return (g_func_flag[0](&s[*i][*j], opts, FLAG_H));
		flag = (1 << n);
		
		debug_print("PARS: %c param: %i\n", s[*i][*j], flag_need_param(flag));
			
		if (flag_need_param(flag))
		{
			if (s[*i][*j + 1] != '\0')
				(*j)++;
			else if (s[*i + 1] != NULL)
			{
				(*i)++;
				(*j) = 0;
			}
			else
				return (-1);
		}

		ret = g_func_flag[n](&s[*i][*j], opts, flag);
		if (ret != 0)
			return (ret);
		(*j)++;
	}

	return (0);
}
