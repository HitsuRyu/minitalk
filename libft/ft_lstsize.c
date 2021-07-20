#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		len;

	len = 0;
	tmp = lst;
	if (lst == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len + 1);
}
