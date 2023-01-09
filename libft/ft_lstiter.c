#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	(*f)(lst);
	while (lst->next)
	{
		lst = lst->next;
		(*f)(lst);
	}
}
