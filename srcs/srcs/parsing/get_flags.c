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
	int i;
	int j;
	int n;

	i = 0;
	//TODO init defautlt value of flags
	(void)opts;
	while (s[i])
	{
		j = 0;
		if (s[i][j] && s[i][j] != '-')
		{

		}
		else 
		{

		}
		++i;
	}
	return (1);
}
