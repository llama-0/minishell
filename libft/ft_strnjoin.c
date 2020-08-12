#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t j)
{
	size_t	i;
	size_t	len1;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len1 = ft_strlen(s1);
	if (!(res = ft_strnew(len1 + j + 2)))
		return (NULL);
	while (i < (len1 + j))
	{
		if (i < len1)
			res[i] = s1[i];
		else if (i - len1 < j)
			res[i] = s2[i - len1];
		i++;
	}
	res[i] = '\0';
	return (res);
}
