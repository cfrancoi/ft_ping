#include <options.h>
#include <debug.h>


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

int 	get_flags(const char *s, int *flags)
{
	int i;
	int n;

	i = 0;
	(void)flags;
	while (s[i])
	{
		n = ft_strchr_index(FLAGS_LIST, (const int)s[i]);
		if (n == -1)	
			return (0);
		debug_print("PARS: %c param: %i\n", s[i], flag_need_param((1 << n)));	
		++i;
	}
	return (1);
}
