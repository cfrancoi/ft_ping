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

	i = 0;
	j = 0;
	//TODO init defautlt value of flags
	while (s[i] != NULL)
	{
		debug_print("FT_PING: get flags : %s\n", s[i]);
		j = 0;
		if (s[i] && s[i][j] != '-')
		{

		}
		else 
		{
			j++; // skip '-'
			if (set_flags(s, &i, &j, opts))
				return (1);
		}
		if (s[i])
			++i;
	}
	return (0);
}
