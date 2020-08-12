#include "libft.h"

/*
** flag == 2 -- '\n' then usual output
** flag == 0 -- usual output
** flag != 0 -- usual output ':' '\n' (for ls error printing)
*/

void	ft_putendl(char const *s, int flag)
{
	if (flag == 2)
		ft_putchar_base('\n', 1);
	ft_putstr_base(s, 1);
	if (flag != 0)
		ft_putchar_base(':', 1);
	ft_putchar_base('\n', 1);
}
