/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:53:30 by mdaifi            #+#    #+#             */
/*   Updated: 2021/04/30 17:46:53 by mdaifi           ###   ########.fr       */
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
			rra(a);
		}
		else
			ra(a);
	}
	else if (a->t[a->i] > a->t[a->i + 1] && a->t[a->i] < a->t[a->size - 1])
		sa(a);
	else if (a->t[a->i] < a->t[a->i + 1] && a->t[a->i] > a->t[a->size - 1])
		rra(a);
	else if (a->t[a->i] < a->t[a->i + 1] && a->t[a->i] < a->t[a->size - 1])
	{
		if (a->t[a->i + 1] > a->t[a->size - 1])
		{
			sa(a);
			ra(a);
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
				ra(a);
				min--;
			}
			pb(a, b);
			i = a->i;
		}
		else
		{
			while (min < a->size)
			{
				rra(a);
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

void	stack_less_than_hund(t_push_swap *tmp, t_push_swap *a, t_push_swap *b)
{
	int	i;
	int	max;
	int	split;
	int	half_size;
	int	chunk[5];

	chunk[0] = find_median(tmp, 0, 20);
	chunk[1] = find_median(tmp, 20, 40);
	chunk[2] = find_median(tmp, 40, 60);
	chunk[3] = find_median(tmp, 60, 80);
	chunk[4] = find_median(tmp, 80, 100);
	i = 0;
	split = 10;
	while (a->i < a->size)
	{
		// if (a->i == split)
		// 	split += 10;
		if (a->t[i] < tmp->t[50])
		{
			half_size = (a->size - a->i) / 2;
			if (half_size % 2 == 0)
				half_size++;
			if (i - a->i <= half_size)
			{
				while (i - a->i > 0)
				{
					ra(a);
					i--;
				}
				pb(a, b);
				i = a->i;
			}
			else
			{
				while (i < a->size)
				{
					rra(a);
					i++;
				}
				pb(a ,b);
				i = a->i;
			}
		}
		else
			i++;
		// if (b->size - b->i > 1 && b->t[b->i] < b->t[b->i + 1])
		// 	sb(b);
	}
		// print_table(a, b);
	// pa(b, a);
	// // print_table(a, b);
	// pa(b, a);
	// // print_table(a, b);
	// if (a->t[a->i] > a->t[a->i + 1])
	// 	sa(a);
	// while (b->i < b->size)
	// {
	// 	if (b->t[b->i] == tmp->t[tmp->size - 1])
	// 	{
	// 		pa(b, a);
	// 		ra(a);
	// 	}
	// 	max = a->t[a->size - 1];
	// 		while (a->t[a->i] < b->t[b->i] && a->t[a->i] < max)
	// 		{
	// 			// print_table(a, b);
	// 			ra(a);
	// 			// sleep(1);
	// 		}
	// 		pa(b, a);
	// 		while (a->t[a->size - 1] < a->t[a->i])
	// 			rra(a);
	// 	// if (a->t[a->i] > a->t[a->i + 1] && a->t[a->i] < a->t[a->size - 1])
	// 	// {
	// 	// 	sa(a);
	// 	// 	if (a->t[a->i] < a->t[a->i + 1] && a->t[a->i + 1] > a->t[a->i + 2])
	// 	// 		ra(a);
	// 	// 	while (a->t[a->i] > a->t[a->i + 1])
	// 	// 	{
	// 	// 		sa(a);
	// 	// 		ra(a);
	// 	// 	}
	// 	// }
	// 	// else if (a->t[a->i] > a->t[a->i + 1] && a->t[a->i] > a->t[a->size - 1])
	// 	// 	ra(a);
	// 	// print_table(a, b);
	// }
	// if (check_order(a) == 0)
	// 	printf("OK\n");
}

void	push_swap(t_push_swap *a, t_push_swap *b, t_push_swap *tmp)
{
	// if (a->size == 2)
	// 	if (a->t[a->i] > a->t[a->i + 1])
	// 		sa(a);
	if (a->size == 3)
		stack_of_three(a);
	// stack_less_than_ten(a, b);
	stack_less_than_hund(tmp, a, b);
}