/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:44:45 by garibeir          #+#    #+#             */
/*   Updated: 2022/11/14 14:07:55 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ps;

	ps = (char *)s;
	i = 0;
	while (i <= (int)ft_strlen(ps))
	{
		if (ps[i] == (char)c)
			return (&ps[i]);
		i++;
	}
	return (0);
}

/*
int main(void)
{
	char *s = "Hello";
	int c = 108;

	char *p1 = ft_strchr(s, c);
	char *p2 = strchr(s, c);
	
	printf("Mine: %p\n", p1);
	printf("Actual: %p\n", p2);

}
*/