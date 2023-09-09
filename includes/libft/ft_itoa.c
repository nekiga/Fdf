/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:36:08 by garibeir          #+#    #+#             */
/*   Updated: 2022/11/13 17:31:24 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countlen(int n)
{
	int	c;

	c = 0;
	if (n <= 0)
		c++;
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	numb;

	numb = n;
	len = ft_countlen(numb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (numb < 0)
	{
		str[0] = '-';
		numb *= -1;
	}
	if (numb == 0)
		str[0] = '0';
	str[len] = '\0';
	len--;
	while (numb)
	{
		str[len] = numb % 10 + '0';
		len--;
		numb /= 10;
	}
	return (str);
}
