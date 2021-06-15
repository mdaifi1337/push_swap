/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_elmnt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:43:15 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/12 14:52:17 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_place(t_push_swap *a, int nbr)
{
	int	i;
	int	max_val_pos;

	i = 0;
	a->second = a->size;
	if (nbr < a->t[0] && nbr > a->t[a->second - 1])
		return (i);
	while (i < a->second)
	{
		if (nbr > a->t[i] && nbr < a->t[i + 1])
			return (i + 1);
		else if (nbr > a->t[a->second - 2] && nbr < a->t[a->second - 1])
			return (-(a->size - a->second + 1));
		a->second--;
		i++;
	}
	max_val_pos = max_val(a->t, a->size) + 1;
	if (max_val_pos == a->size)
		max_val_pos = 0;
	if (max_val_pos > a->size - max_val_pos)
		return (-(a->size - max_val_pos));
	return (max_val_pos);
}

static int	*allocate_and_init(t_push_swap *a, t_push_swap *b)
{
	int	*res;

	res = (int *)malloc(sizeof(int) * 2);
	res[0] = a->size;
	res[1] = b->size;
	return (res);
}

static void	compare_top_b(int *tmp, int **res, t_push_swap *a, t_push_swap *b)
{
	if (count_ops(tmp[0], tmp[1]) < count_ops((*res)[0], (*res)[1]))
	{
		free(*res);
		*res = search_top_b(a, b, tmp);
	}
}

void	find_best(t_push_swap *a, t_push_swap *b)
{
	int	i;
	int	*tmp;
	int	*res;

	i = -1;
	tmp = (int *)malloc(sizeof(int) * 2);
	res = allocate_and_init(a, b);
	while (++i < b->second)
	{
		tmp[0] = find_place(a, b->t[i]);
		tmp[1] = i;
		compare_top_b(tmp, &res, a, b);
		tmp[0] = find_place(a, b->t[b->second - 1]);
		tmp[1] = -i;
		if (count_ops(tmp[0], tmp[1]) < count_ops(res[0], res[1]))
		{
			free(res);
			res = search_bot_b(a, b, tmp, i);
		}
		b->second--;
	}
	free(res);
	free(tmp);
}
