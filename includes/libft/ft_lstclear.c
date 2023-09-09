/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:19:57 by garibeir          #+#    #+#             */
/*   Updated: 2022/11/14 14:12:07 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nnext;

	if (!lst)
		return ;
	while (*lst)
	{
		nnext = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nnext;
	}
	*lst = NULL;
}
