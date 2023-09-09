/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:45:20 by garibeir          #+#    #+#             */
/*   Updated: 2022/11/13 18:45:58 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (!s)
		return (NULL);
	if (c == 0)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == (char )c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
/*
int main(void)
{
   char *s = "Hjgfkfjkello";
	int c = 108;

	char *p1 = ft_strrchr(s, c);
	char *p2 = strchr(s, c);
	
	printf("Mine: %p\n", p1);
	printf("Actual: %p\n", p2);

}
*/