#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*saved;

	tmp = *lst;
	while (tmp != NULL)
	{
		saved = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = saved;
	}
	*lst = NULL;
}
