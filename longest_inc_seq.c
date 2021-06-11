/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_inc_seq.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:32:10 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/09 14:39:04 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_lis(int nbr, int *lis_elm, int size)
{
	int	i;
	int	res;

	res = 0;
	i = -1;
	while (++i < size && res == 0)
	{
		if (nbr == lis_elm[i])
			res = 1;
	}
	return (res);
}

static void	tmp_ra_rra(int i, t_push_swap *tmp)
{
	if (i < tmp->size - i)
	{
		while (i > 0)
		{
			ra(tmp, "KO\n");
			i--;
		}
	}
	else
	{
		while (tmp->size - i > 0)
		{
			rra(tmp, "KO\n");
			i++;
		}
	}
}

static int	*fill_lis(int *tmp, int size)
{
	int	i;
	int	j;
	int	*lis;

	lis = (int *)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		lis[i] = 1;
	i = 0;
	while (++i < size)
	{
		j = 0;
		while (j < i)
		{
			if (tmp[j] < tmp[i] && lis[j] + 1 >= lis[i])
				lis[i] = lis[j] + 1;
			j++;
		}
	}
	return (lis);
}

int	*longest_inc_seq(t_push_swap *a, int *max_lis)
{
	int			i;
	int			j;
	int			*lis;
	int			*lis_elm;
	t_push_swap	*tmp;

	tmp = (t_push_swap *)malloc(sizeof(t_push_swap));
	tmp->t = (int *)malloc(sizeof(int) * a->size);
	tmp->size = a->size;
	i = -1;
	while (++i < a->size)
		tmp->t[i] = a->t[i];
	i++;
	tmp_ra_rra(min_val(tmp->t, a->size), tmp);
	lis = fill_lis(tmp->t, a->size);
	*max_lis = lis[max_val(lis, a->size)];
	j = *max_lis;
	lis_elm = (int *)malloc(sizeof(int) * j);
	while (--i >= 0 && j)
		if (lis[i] == j)
			lis_elm[--j] = tmp->t[i];
	free(tmp->t);
	free(tmp);
	free(lis);
	return (lis_elm);
}
