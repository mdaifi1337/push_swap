/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:53:30 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/04 16:29:16 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_order(t_push_swap *t)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
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

void	stack_of_three(t_push_swap *a)
{
	if (a->t[0] > a->t[1] && a->t[0] > a->t[a->size - 1])
	{
		if (a->t[1] > a->t[a->size - 1])
		{
			sa(a);
			rra(a, "rra\n");
		}
		else
			ra(a, "ra\n");
	}
	else if (a->t[0] > a->t[1] && a->t[0] < a->t[a->size - 1])
		sa(a);
	else if (a->t[0] < a->t[1] && a->t[0] > a->t[a->size - 1])
		rra(a, "rra\n");
	else if (a->t[0] < a->t[1] && a->t[0] < a->t[a->size - 1])
	{
		if (a->t[1] > a->t[a->size - 1])
		{
			sa(a);
			ra(a, "ra\n");
		}
	}
}

int		max_val(int *t, int len)
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

int		min_val(int *t, int len)
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

int		in_lis(int nbr, int *lis_elm, int size)
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

int		find_place(t_push_swap *a, int nbr)
{
	int	i;
	int	top;
	int	bot;
	int	max_val_pos;

	i = 0;
	a->second = a->size;
	if (nbr < a->t[0] && nbr > a->t[a->second - 1])
		return (i);
	while (i < a->size)
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
	return max_val_pos;
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

void	find_best(t_push_swap *a, t_push_swap *b)
{
	int	i;
	int	tmp[2];
	int	res[2];

	i = 0;
	a->i_bot = 0;
	res[0] = a->size;
	res[1] = b->size;
	b->second = b->size;
	while (i < b->second)
	{
		tmp[0] = find_place(a, b->t[i]);
		tmp[1] = i;
		if (count_ops(tmp[0], tmp[1]) < count_ops(res[0], res[1]))
		{
			res[0] = abs(tmp[0]);
			res[1] = abs(tmp[1]);
			if (tmp[0] == -1)
			{
				a->bot = 1;
				a->top = 0;
			}
			else if (tmp[0] <= 0 && abs(tmp[0]) <= res[0])
			{
				a->bot = res[0];
				a->top = 0;
			}
			else if (tmp[0] < 0 && b->top == 0  && a->top)
			{
				a->bot = res[0];
			}
			else if (tmp[0] > 0)
			{
				a->top = tmp[0];
				a->bot = 0;
			}
			b->top = i;
			b->bot = 0;
		}
		tmp[0] = find_place(a, b->t[b->second - 1]);
		tmp[1] = -i;
		if (count_ops(tmp[0], tmp[1]) < count_ops(res[0], res[1]))
		{
			res[0] = abs(tmp[0]);
			res[1] = abs(tmp[1]);
			if (b->size - b->second == 0)
				res[1] = 1;
			if (tmp[0] == -1)
			{
				a->bot = 1;
				a->top = 0;
			}
			else if (tmp[0] <= 0 && abs(tmp[0]) <= res[0])
			{
				a->bot = res[0];
				a->top = 0;
			}
			else if (tmp[0] < 0 && b->top == 0)
			{
				a->bot = res[0];
			}
			else if (tmp[0] > 0)
			{
				a->top = tmp[0];
				a->bot = 0;
			}
			b->top = 0;
			b->bot = i;
			if (i == 0)
				b->bot = -1;
		}
		b->second--;
		i++;
	}
}

void	stack_less_than_hund(t_push_swap *a, t_push_swap *b)
{
	int	i;
	int	j;
	int	max;
	int	min;
	t_push_swap	*tmp;
	int	*res;
	int	*lis;
	int	*lis_elm;
	int	curr_val;

	tmp = (t_push_swap *)malloc(sizeof(t_push_swap));
	tmp->size = a->size;
	tmp->t = (int *)malloc(sizeof(int) * a->size);
	i = 0;
	while (i < a->size)
	{
		tmp->t[i] = a->t[i];
		i++;
	}
	min = min_val(tmp->t, a->size);
	while (min > 0)
	{
		ra(tmp, "KO\n");
		min--;
	}
	lis = (int *)malloc(sizeof(int) * a->size);
	i = -1;
	while (++i < a->size)
		lis[i] = 1;
	i = 0;
	while (++i < a->size)
	{
		j = 0;
		while (j < i)
		{
			if (tmp->t[j] < tmp->t[i] && lis[j] + 1 >= lis[i])
				lis[i] = lis[j] + 1;
			j++;
		}
	}
	curr_val = lis[max_val(lis, a->size)];
	lis_elm = (int *)malloc(sizeof(int) * curr_val);
	while (i >= 0 && curr_val)
	{
		if (lis[i] == curr_val)
			lis_elm[--curr_val] = tmp->t[i];
		i--;
	}
	free(tmp->t);
	free(tmp);
	curr_val = lis[max_val(lis, a->size)];
	i = 0;
	while (curr_val < a->size)
	{
		if (in_lis(a->t[0], lis_elm, curr_val))
			ra(a, "ra\n");
		else
			pb(a, b);
	}
	i = 0;
	a->second = a->size;
	b->second = b->size;
	while (b->size)
	{
		a->top = 0;
		a->bot = 0;
		b->top = 0;
		b->bot = 0;
		find_best(a, b);
		if (a->bot > 0 && a->bot < a->top)
			a->top = 0;
		if (a->top * b->top != 0)
		{
			j = a->top;
			if (b->top < j)
				j = b->top;
			while (j > 0)
			{
				rr(a, b);
				j--;
				a->top--;
				b->top--;
			}
			while (a->top > 0)
			{
				ra(a, "ra\n");
				a->top--;
			}
			while (b->top > 0)
			{
				rb(b, "rb\n");
				b->top--;
			}
			pa(b, a);
		}
		else if (a->bot * b->bot != 0)
		{
			if (b->bot == -1)
				b->bot = 0;
			j = a->bot;
			if (b->bot < j)
				j = b->bot;
			if (j == a->bot)
				j--;
			while (j >= 0)
			{
				rrr(a, b);
				j--;
				a->bot--;
				b->bot--;
			}
			while (a->bot > 0)
			{
				rra(a, "rra\n");
				a->bot--;
			}
			while (b->bot >= 0)
			{
				rrb(b, "rrb\n");
				b->bot--;
			}
			pa(b, a);
		}
		else
		{
			if (a->top)
			{
				while (a->top > 0)
				{
					ra(a, "ra\n");
					a->top--;
				}
			}
			else if (a->bot)
			{
				while (a->bot > 0)
				{
					rra(a, "rra\n");
					a->bot--;
				}
			}
			if (b->top)
			{
				while (b->top > 0)
				{
					rb(b, "rb\n");
					b->top--;
				}
			}
			else if (b->bot)
			{
				if (b->bot == -1)
				b->bot = 0;
				while (b->bot >= 0)
				{
					rrb(b, "rrb\n");
					b->bot--;
				}
			}
			pa(b, a);
		}
	}
	max = max_val(a->t, a->size);
	if (max > a->size - max)
	{
		max = a->size - max - 1;
		while (max > 0)
		{
			rra(a, "rra\n");
			max--;
		}
	}
	else
	{
		while (max >= 0)
		{
			ra(a, "ra\n");
			max--;
		}
	}
}

void	push_swap(t_push_swap *a, t_push_swap *b)
{
	// if (a->size == 2)
	// 	if (a->t[a->i] > a->t[a->i + 1])
	// 		sa(a);
	stack_less_than_hund(a, b);
}