/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:43:42 by garibeir          #+#    #+#             */
/*   Updated: 2022/11/11 17:09:38 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	sign = 1;
	i = 0;
	res = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
		res = res * 10 + str[i++] - 48;
	return (res * sign);
}

/*int main(void)
 {
	\t\n\r\v\f
	const char str[] = "-1341";

	int str1 = atoi(str);
	int str2 = ft_atoi(str);
	printf("%d\n", str1);
	printf("%d\n", str2);
 }
 */
