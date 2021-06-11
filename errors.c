/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:28:17 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/11 15:24:59 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_not_nbr(char **tab)
{
	int	i;
	int	j;
	int	ok;

	i = -1;
	ok = 0;
	while (tab[++i] && !ok)
	{
		j = -1;
		if (tab[i][0] == '-')
			j++;
		while (tab[i][++j] != '\0' && !ok)
		{
			if (!ft_isdigit(tab[i][j]))
			{
				write(2, "Error\n", 7);
				ok = 1;
			}
		}
	}
	return (ok);
}

int	check_for_doubles(t_push_swap *st)
{
	int	i;
	int	j;
	int	ok;

	i = -1;
	ok = 0;
	while (++i < st->size - 1 && !ok)
	{
		j = i;
		while (++j < st->size && !ok)
		{
			if (st->t[i] == st->t[j])
			{
				write(2, "Error\n", 7);
				ok = 1;
			}
		}
	}
	return (ok);
}

static int	compare_to_max_min_int(char **tab, int size, int i)
{
	char	*str;
	int		j;
	int		ok;

	ok = 0;
	j = 0;
	if (size == 10)
		str = ft_itoa(INT_MAX);
	if (size == 11)
		str = ft_itoa(INT_MIN);
	while (tab[i][j] && !ok)
	{
		if (tab[i][j] > str[j])
		{
			write(2, "Error\n", 7);
			ok = 1;
		}
		j++;
	}
	free(str);
	return (ok);
}

int	check_max_min_int(char **tab)
{
	int		i;
	int		size;
	int		ok;

	i = -1;
	ok = 0;
	while (tab[++i] && !ok)
	{
		size = 0;
		while (tab[i][size])
			size++;
		if (size > 11)
		{
			write(2, "Error\n", 7);
			ok = 1;
		}
		if (size == 10 || size == 11)
			ok = compare_to_max_min_int(tab, size, i);
	}
	return (ok);
}

void	check_input_vals(char **tab, t_push_swap *st)
{
	if (check_if_not_nbr(tab) || check_for_doubles(st)
		|| check_max_min_int(tab))
		exit(1);
}
