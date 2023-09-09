/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:58:26 by garibeir          #+#    #+#             */
/*   Updated: 2022/11/13 17:29:51 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countwords(const char *str, char c)
{
	int	count;
	int	boolean;

	count = 0;
	boolean = 0;
	while (*str)
	{
		if (*str != c && boolean == 0)
		{
			boolean = 1;
			count++;
		}
		else if (*str == c)
			boolean = 0;
		str++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((countwords(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = ft_substr(s, index, i - index);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
