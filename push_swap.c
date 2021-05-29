/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:53:30 by mdaifi            #+#    #+#             */
/*   Updated: 2021/05/29 17:38:49 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_order(t_push_swap *t)
{
	int	res;
	int	i;

	res = 0;
	i = t->i;
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

int		check_order_desc(t_push_swap *t)
{
	int	res;
	int	i;

	res = 0;
	i = t->i;
	while (i < t->size - 1)
	{
		if (t->t[i] < t->t[i + 1])
		{
			res = 0;
			return (res);
		}
		res = 1;
		i++;
	}
	return (res);
}

void	stack_of_three(t_push_swap *a)
{
	if (a->t[a->i] > a->t[a->i + 1] && a->t[a->i] > a->t[a->size - 1])
	{
		if (a->t[a->i + 1] > a->t[a->size - 1])
		{
			sa(a);
			rra(a, "rra\n");
		}
		else
			ra(a, "ra\n");
	}
	else if (a->t[a->i] > a->t[a->i + 1] && a->t[a->i] < a->t[a->size - 1])
		sa(a);
	else if (a->t[a->i] < a->t[a->i + 1] && a->t[a->i] > a->t[a->size - 1])
		rra(a, "rra\n");
	else if (a->t[a->i] < a->t[a->i + 1] && a->t[a->i] < a->t[a->size - 1])
	{
		if (a->t[a->i + 1] > a->t[a->size - 1])
		{
			sa(a);
			ra(a, "ra\n");
		}
	}
}

void	stack_less_than_ten(t_push_swap *a, t_push_swap *b)
{
	int	i;
	int	j;
	int	min;
	int	half_size;

	i = a->i;
	while (i < a->size - 1 && (a->size - a->i > 3))
	{
		min = i;
		j = i + 1;
		while (j < a->size)
		{
			if (a->t[j] < a->t[min])
				min = j;
			j++;
		}
		half_size = (a->size - a->i) / 2;
		if (half_size % 2 == 0)
			half_size++;
		if (min - a->i <= half_size)
		{
			while (min - a->i > 0)
			{
				ra(a, "ra\n");
				min--;
			}
			pb(a, b);
			i = a->i;
		}
		else
		{
			while (min < a->size)
			{
				rra(a, "rra\n");
				min++;
			}
			pb(a ,b);
			i = a->i;
		}
	}
	stack_of_three(a);
	while (b->i < b->size)
		pa(b, a);
}

int		max_val(int *t, int len)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (t[j] > t[i])
				max = j;
			j++;
		}
		i++;
	}
	return (t[max]);
}

void	shortest_path(t_push_swap *a, int nbr)
{
	int	i;

	i = a->i;
	a->top = 0;
	a->bot = 0;
	while (nbr > a->t[i])
	{
		a->top++;
		i++;
	}
	i = a->size;
	while (nbr < a->t[i - 1])
	{
		a->bot++;
		i--;
	}
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

void	stack_less_than_hund(t_push_swap *tmp, t_push_swap *a, t_push_swap *b)
{
	int	i;
	int	j;
	int	curr_val;
	int	*lis;
	int	*lis_elm;

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
			if (a->t[j] < a->t[i] && lis[j] + 1 >= lis[i])
				lis[i] = lis[j] + 1;
			j++;
		}
	}
	curr_val = max_val(lis, a->size);
	lis_elm = (int *)malloc(sizeof(int) * curr_val);
	while (i > 0 && curr_val)
	{
		if (lis[i] == curr_val)
			lis_elm[--curr_val] = a->t[i];
		i--;
	}
	i = -1;
	curr_val = max_val(lis, a->size);
	// while (++i < curr_val)
	// 	printf("lis_elm[%d] : %d\n", i, lis_elm[i]);
	i = 0;
	while (curr_val < a->size - a->i)
	{
		if (in_lis(a->t[a->i], lis_elm, curr_val))
			ra(a, "ra\n");
		else
			pb(a, b);
	}
	// print_table(a, b);
	// if (check_order(a) == 0)
	// 	write(1, "OK\n", 3);
}

void	push_swap(t_push_swap *a, t_push_swap *b, t_push_swap *tmp)
{
	// if (a->size == 2)
	// 	if (a->t[a->i] > a->t[a->i + 1])
	// 		sa(a);
	// stack_less_than_ten(a, b);
	stack_less_than_hund(tmp, a, b);
}