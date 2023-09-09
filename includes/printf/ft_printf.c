/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:34:31 by garibeir          #+#    #+#             */
/*   Updated: 2022/11/26 17:23:41 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	_vprint(va_list args, const char var)
{
	int	len;

	len = 0;
	if (var == 'c')
		len += ft_putchar(va_arg(args, int));
	if (var == 's')
		len += ft_putstr(va_arg(args, char *));
	if (var == 'd' || var == 'i')
		len += ft_putnbr(va_arg(args, int), var);
	if (var == 'u')
		len += ft_uputnbr(va_arg(args, unsigned int));
	if (var == 'p')
		len += ft_putpointer(va_arg(args, unsigned long));
	if (var == 'x' || var == 'X')
		len += ft_puthex(va_arg(args, unsigned int), var);
	if (var == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	unsigned int	i;
	unsigned int	len;
	va_list			args;

	i = 0;
	len = 0;
	va_start(args, s);
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += _vprint(args, s[i + 1]);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (len);
}
