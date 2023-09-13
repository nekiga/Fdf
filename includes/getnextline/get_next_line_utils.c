/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:03:13 by garibeir          #+#    #+#             */
/*   Updated: 2023/09/13 15:50:37 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	string = malloc(ft_strlen1(s1) + ft_strlen1(s2) + 1);
	if (!string)
		return (NULL);
	while (s1 && s1[i])
		string[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		string[j++] = s2[i];
		if (s2[i++] == '\n')
			break ;
	}
	string[j] = 0;
	free(s1);
	return (string);
}

size_t	ft_strlen1(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

int	ft_clean(char *s)
{
	int	bool;
	int	i;
	int	j;

	i = 0;
	j = 0;
	bool = 0;
	while (s[i])
	{
		if (bool)
			s[j++] = s[i];
		if (s[i] == '\n')
			bool = 1;
		s[i] = 0;
		i++;
	}
	return (bool);
}
