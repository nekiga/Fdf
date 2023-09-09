/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:44:26 by garibeir          #+#    #+#             */
/*   Updated: 2022/11/11 16:37:37 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;
	size_t	i;

	i = 0;
	cdest = (char *) dest;
	csrc = (char *) src;
	if (dest == src || n == 0)
		return (dest);
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return ((void *) cdest);
}
