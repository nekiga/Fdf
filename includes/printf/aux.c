/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:01:29 by garibeir          #+#    #+#             */
/*   Updated: 2022/11/26 16:56:43 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

long long	ft_countlen(long long n)
{
	long long	c;

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

char	*ft_itoap(long long n, int flag)
{
	char		*str;
	int			len;

	len = ft_countlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n < 0)
	{
		if (flag != 'u')
			str[0] = '-';
		else
			len--;
		n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (n)
	{
		str[len] = n % 10 + '0';
		len--;
		n /= 10;
	}
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
