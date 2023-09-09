/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:44:35 by garibeir          #+#    #+#             */
/*   Updated: 2022/11/13 17:55:40 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *src, const void *dest, size_t n)
{
	size_t	len;

	len = 0;
	if (!src && !dest)
		return (0);
	if (dest < src)
	{
		len = n;
		while (len > 0)
		{
			len--;
			((unsigned char *)src)[len] = ((unsigned char *)dest)[len];
		}
	}
	else
	{
		len = 0;
		while (len < n)
		{
			((unsigned char *)src)[len] = ((unsigned char *)dest)[len];
			len++;
		}
	}
	return (src);
}
