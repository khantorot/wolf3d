#include "libft.h"

int	ft_strequ(const char *s1, const char *s2)
{
	return (ft_strnequ(s1, s2, ft_max(ft_strlen(s1), ft_strlen(s2))));
}
