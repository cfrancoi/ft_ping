#include <options.h>
#include <debug.h>




/**
 *	s //av
 *	flags // struct of flags
 *
 *	pars s and set opt
*/
int 	get_flags(const char **s, t_options *opts)
{
	size_t	i;
	size_t	j;
	int		ret;

	i = 0;
	j = 0;
	ret = 0;
	init_t_options(opts);
	while (s[i] != NULL)
	{
		debug_print("FT_PING: get flags : %s\n", s[i]);
		j = 0;
		if (s[i] && s[i][j] != '-')
		{
			opts->host = &s[i];
		}
		else 
		{
			j++; // skip '-'
			ret = set_flags(s, &i, &j, opts);
			if (ret != 0 && ret != 1)
				return (ret);
		}
		if (s[i])
			++i;
	}
	return (0);
}