#include "libft.h"

char	*ft_true_strtrim(char const *s)
{
	size_t	head;
	size_t	end;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	head = i;
	i = len - 1;
	j = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i--;
		j++;
	}
	end = j;
	return (ft_strndup(s + head, len - head - end));
}
