#include "libft.h"
#include <stdlib.h>

void	ft_lstdelfn(void *obj, size_t size)
{
	(void)size;
	ft_memdel(&obj);
}
