/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:04:19 by mdaifi            #+#    #+#             */
/*   Updated: 2019/11/04 15:10:44 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**allocate(char *tmp, char c, int j)
{
	char			**str;
	int				i;
	unsigned int	count;

	if ((str = (char **)malloc(sizeof(char *) * (j + 2))))
	{
		i = 0;
		j = 0;
		count = 0;
		while (tmp[j])
			if (tmp[j] != c)
			{
				while (tmp[j] != c && tmp[j])
					j++;
				str[i] = ft_substr(tmp, count, (size_t)(j - count));
				count = j + 1;
				i++;
			}
			else
				count = ++j;
		str[i] = NULL;
		free(tmp);
		return (str);
	}
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char			*tmp;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	tmp = ft_strtrim(s, &c);
	if (tmp != NULL)
	{
		while (tmp[i])
		{
			if (tmp[i] == c && tmp[i + 1] != c)
				j++;
			i++;
		}
		return (allocate(tmp, c, j));
	}
	return (NULL);
}
