/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:53:30 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/12 15:15:35 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	align_a(t_push_swap *a)
{
	int	max;

	max = max_val(a->t, a->size);
	if (max > a->size - max)
	{
		max = a->size - max - 1;
		while (--max >= 0)
			rra(a, "rra\n");
	}
	else
	{
		while (--max >= -1)
			ra(a, "ra\n");
	}
}

void	insert_next(t_push_swap *a, t_push_swap *b)
{
	while (b->size > 0)
	{
		init_vars(a, b);
		find_best(a, b);
		if (a->bot > 0 && a->bot < a->top)
			a->top = 0;
		if (a->top * b->top != 0)
			smart_rotate_top(a, b);
		else if (a->bot * b->bot != 0)
			smart_rotate_bot(a, b);
		else
		{
			rotate_a(a);
			rotate_b(b);
			pa(b, a, "pa\n");
		}
	}
}

void	sort_stack(t_push_swap *a, t_push_swap *b)
{
	int	max;
	int	*lis_elm;

	lis_elm = longest_inc_seq(a, &max);
	while (max < a->size)
	{
		if (in_lis(a->t[0], lis_elm, max))
			ra(a, "ra\n");
		else
			pb(a, b, "pb\n");
	}
	free(lis_elm);
	a->second = a->size;
	b->second = b->size;
	insert_next(a, b);
	align_a(a);
}

void	two_args(t_push_swap *a, char **tab)
{
	char	**tmp;
	int		i;

	a->size = 0;
	tmp = ft_split(tab[1], ' ');
	while (tmp[a->size])
		a->size++;
	a->t = (int *)malloc(sizeof(int) * a->size);
	if (!a->t)
	{
		ft_free(tmp);
		return ;
	}
	i = 0;
	while (i < a->size)
	{
		a->t[i] = ft_atoi(tmp[i]);
		i++;
	}
	check_input_vals(tmp, a);
	ft_free(tmp);
}

void	push_swap(char **tab, int size)
{
	t_push_swap	a;
	t_push_swap	b;
	int			i;

	a.size = size - 1;
	b.size = 0;
	if (size == 2)
		two_args(&a, tab);
	else
	{
		a.t = (int *)malloc(sizeof(int) * a.size);
		i = -1;
		while (++i < a.size)
			a.t[i] = ft_atoi(tab[i + 1]);
		check_input_vals(tab + 1, &a);
	}
	if (a.size == 2 && !check_order(&a))
		if (a.t[0] > a.t[1])
			sa(&a, "sa\n");
	if (a.size == 3 && !check_order(&a))
		stack_of_three(&a);
	else if (a.size > 3 && !check_order(&a))
		sort_stack(&a, &b);
	free(a.t);
}
