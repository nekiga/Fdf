/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:33:15 by garibeir          #+#    #+#             */
/*   Updated: 2022/11/26 17:01:25 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

long long	ft_countlen(long long n);
int			ft_uputnbr(unsigned int num);
int			ft_putchar(char c);
int			ft_putstr(char *s);
int			ft_putnbr(long long num, int flag);
int			ft_puthex(unsigned long long num, int base);
int			ft_putpointer(unsigned long pp);
int			ft_putpercent(char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_itoap(long long n, int flag);
size_t		ft_strlen(const char *str);
int			ft_printf(const char *s, ...);
char		*ft_uitoa(unsigned int n);

#endif