/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:24:06 by garibeir          #+#    #+#             */
/*   Updated: 2022/11/26 16:10:22 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_uitoa(unsigned int n);

int	ft_ucountlen(unsigned int n)
{
	int	c;

	c = 0;
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

int	ft_uputnbr(unsigned int num)
{
	int		len;
	char	*str;

	str = ft_uitoa(num);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	unsigned int	len;

	len = ft_ucountlen(n);
	if (!len)
		len = 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (n)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}
