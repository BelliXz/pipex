/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:46:06 by paradari          #+#    #+#             */
/*   Updated: 2024/02/17 15:46:08 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !del || !f)
		return (NULL);
	new = NULL;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
			ft_lstclear(&tmp, del);
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
