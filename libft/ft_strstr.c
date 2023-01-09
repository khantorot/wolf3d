#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	char *a;
	char *b;

	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1)
	{
		a = (char *)s1;
		b = (char *)s2;
		while (*b && *a == *b)
		{
			a++;
			b++;
		}
		if (*b == '\0')
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
