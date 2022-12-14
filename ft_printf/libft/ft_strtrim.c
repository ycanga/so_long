/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:33:27 by ycanga            #+#    #+#             */
/*   Updated: 2022/08/28 19:33:28 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checker(char c, char const *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s2[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	j = ft_strlen(s1);
	while (s1[i] && checker(s1[i], s2))
		i++;
	while (j > i && checker(s1[j - 1], s2))
		j--;
	str = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	while (i < j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}
