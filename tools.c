/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:24:14 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/10 15:45:24 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_push_swap *t)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (t->size == 0)
		res = 1;
	while (i < t->size - 1)
	{
		if (t->t[i] > t->t[i + 1])
		{
			res = 1;
			return (res);
		}
		i++;
	}
	return (res);
}

int	max_val(int *t, int len)
{
	int	i;
	int	max;

	i = 1;
	max = 0;
	while (i < len)
	{
		if (t[i] > t[max])
			max = i;
		i++;
	}
	return (max);
}

int	min_val(int *t, int len)
{
	int	i;
	int	min;

	i = 1;
	min = 0;
	while (i < len)
	{
		if (t[i] < t[min])
			min = i;
		i++;
	}
	return (min);
}

int	count_ops(int pos_a, int pos_b)
{
	if (pos_a * pos_b > 0)
	{
		if (abs(pos_b) > abs(pos_a))
			pos_a = abs(pos_b);
		return (abs(pos_a));
	}
	else
		return (abs(pos_a) + abs(pos_b));
}

void	init_vars(t_push_swap *a, t_push_swap *b)
{
	a->top = 0;
	a->bot = 0;
	b->top = 0;
	b->bot = 0;
	b->second = b->size;
}
