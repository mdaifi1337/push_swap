/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:53:30 by mdaifi            #+#    #+#             */
/*   Updated: 2021/05/25 15:34:18 by mdaifi           ###   ########.fr       */
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
			rra(a, 1);
		}
		else
			ra(a, 1);
	}
	else if (a->t[a->i] > a->t[a->i + 1] && a->t[a->i] < a->t[a->size - 1])
		sa(a);
	else if (a->t[a->i] < a->t[a->i + 1] && a->t[a->i] > a->t[a->size - 1])
		rra(a, 1);
	else if (a->t[a->i] < a->t[a->i + 1] && a->t[a->i] < a->t[a->size - 1])
	{
		if (a->t[a->i + 1] > a->t[a->size - 1])
		{
			sa(a);
			ra(a, 1);
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
				ra(a, 1);
				min--;
			}
			pb(a, b);
			i = a->i;
		}
		else
		{
			while (min < a->size)
			{
				rra(a, 1);
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

int		is_max(t_push_swap *t, int nbr)
{
	int	i;
	int	res;

	i = t->i;
	res = 0;
	while (i < t->size)
	{
		if (nbr < t->t[i])
			res = 1;
		i++;
	}
	return (res);
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

void	stack_less_than_hund(t_push_swap *tmp, t_push_swap *a, t_push_swap *b)
{
	int	max;
	int	count;
	int	count_a;
	int	count_b;
	int	first;
	int	second;
	int	split;

	first = 0;
	second = a->size;
	split = 4;
	count_b = 0;
	// max = tmp->size - count_b;
	while (a->i < a->size / 2)
	{
		while (a->t[first] > tmp->t[(tmp->size / 2) - 1])
			first++;
		while (a->t[second - 1] > tmp->t[(tmp->size / 2) - 1])
			second--;
		if (first - a->i < a->size - second)
		{
			while (first - a->i > 0)
			{
				ra(a, 1);
				first--;
			}
			// print_table(a, b);
			pb(a, b);
		}
		else
		{
			while (second <= a->size)
			{
				rra(a, 1);
				second++;
			}
			pb(a ,b);
		}
		first = a->i;
		second = a->size;
	}
	// first = b->i;
	// second = b->size;
	// count = (b->size - b->i) / 3;
	// count_b = count;
	// count_a = 0;
	// tmp->i = 0;
	// split = b->i;
	// while (count_a < 2)
	// {
	// 	if (b->i - split == count_b)
	// 	{
	// 		count_a++;
	// 		count_b += count;
	// 	}
	// 	if (count_a < 2)
	// 	{
	// 		while (b->t[first] > tmp->t[count_b])
	// 			first++;
	// 		while (b->t[second - 1] > tmp->t[count_b])
	// 			second--;
	// 		if (first - b->i < b->size - second)
	// 		{
	// 			while (first - b->i > 0)
	// 			{
	// 				rb(b, "rb\n");
	// 				first--;
	// 			}
	// 			pa(b, a);
	// 		}
	// 		else
	// 		{
	// 			while (second <= b->size)
	// 			{
	// 				rrb(b, "rrb\n");
	// 				second++;
	// 			}
	// 			pa(b ,a);
	// 		}
	// 		first = b->i;
	// 		second = b->size;
	// 		tmp->i++;
	// 	}
	// }
	// // push back to a
	// while (tmp->i > 0)
	// {
	// 	pb(a, b);
	// 	tmp->i--;
	// }
	// first = a->i;
	// second = a->size;
	// count_b += count + 2;
	// while (a->i < a->size)
	// {
	// 	if (a->i == count_b)
	// 	{
	// 		count_a++;
	// 		count_b += count;
	// 	}
	// 	while (a->t[first] > tmp->t[count_b])
	// 		first++;
	// 	while (a->t[second - 1] > tmp->t[count_b])
	// 		second--;
	// 	if (first - a->i < a->size - second)
	// 	{
	// 		while (first - a->i > 0)
	// 		{
	// 			ra(a, 1);
	// 			first--;
	// 		}
	// 		pb(a, b);
	// 	}
	// 	else
	// 	{
	// 		while (second <= a->size)
	// 		{
	// 			rra(a, 1);
	// 			second++;
	// 		}
	// 		pb(a ,b);
	// 	}
	// 	first = a->i;
	// 	second = a->size;
	// }
	// first = b->i;
	// second = b->size;
	// count = 6;
	// count_b = b->size - count;
	// while (b->i < b->size)
	// {
	// 	if (a->i == count_b)
	// 	{
	// 		count_a++;
	// 		count_b -= count;
	// 	}
	// 	while (b->t[first] < tmp->t[count_b])
	// 		first++;
	// 	while (b->t[second - 1] < tmp->t[count_b])
	// 		second--;
	// 	if (first - b->i < b->size - second)
	// 	{
	// 		while (first - b->i > 0)
	// 		{
	// 			rb(b, "rb\n");
	// 			first--;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		while (second <= b->size)
	// 		{
	// 			rrb(b, "rrb\n");
	// 			second++;
	// 		}
	// 	}
	// 	if (!is_max(a, b->t[b->i]))
	// 	{
	// 		pa(b, a);
	// 		ra(a, 1);
	// 	}
	// 	else
	// 	{
	// 		max = a->t[a->size - 1];
	// 		shortest_path(a, b->t[b->i]);
	// 		first = a->top;
	// 		second = a->bot;
	// 		if (a->top == 1)
	// 		{
	// 			pa(b, a);
	// 			sa(a);
	// 		}
	// 		else if (a->top > a->bot)
	// 		{
	// 			while (second > 0)
	// 			{
	// 				rra(a, 1);
	// 				second--;
	// 			}
	// 			pa(b, a);
	// 			ra(a, 1);
	// 			while (a->bot > 0)
	// 			{
	// 				ra(a, 1);
	// 				a->bot--;
	// 			}
	// 		}
	// 		else
	// 		{
	// 			while (first > 0)
	// 			{
	// 				ra(a, 1);
	// 				first--;
	// 			}
	// 			pa(b, a);
	// 			while (a->top > 0)
	// 			{
	// 				rra(a, 1);
	// 				a->top--;
	// 			}
	// 		}
	// 	}
	// 	first = b->i;
	// 	second = b->size;
	// }
	if (check_order(a) == 0)
		printf("OK\n");
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