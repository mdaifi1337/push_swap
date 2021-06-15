/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:39:28 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/15 14:34:19 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_push_swap *a, t_push_swap *b, char *str)
{
	if (a->size > 0)
		ra(a, "KO\n");
	if (b->size > 0)
		rb(b, "KO\n");
	if (!ft_strncmp(str, "rr\n", 4))
		write(1, "rr\n", 3);
}

void	rrr(t_push_swap *a, t_push_swap *b, char *str)
{
	if (a->size > 0)
		rra(a, "KO\n");
	if (b->size > 0)
		rrb(b, "KO\n");
	if (!ft_strncmp(str, "rrr\n", 5))
		write(1, "rrr\n", 4);
}

void	smart_rotate_top(t_push_swap *a, t_push_swap *b)
{
	int	i;

	i = a->top;
	if (b->top < i)
		i = b->top;
	while (--i >= 0)
	{
		rr(a, b, "rr\n");
		a->top--;
		b->top--;
	}
	while (--a->top >= 0)
		ra(a, "ra\n");
	while (--b->top >= 0)
		rb(b, "rb\n");
	pa(b, a, "pa\n");
}

void	smart_rotate_bot(t_push_swap *a, t_push_swap *b)
{
	int	i;

	if (b->bot == -1)
		b->bot = 0;
	i = a->bot;
	if (b->bot < i)
		i = b->bot;
	if (i == a->bot)
		i--;
	while (--i >= -1)
	{
		rrr(a, b, "rrr\n");
		a->bot--;
		b->bot--;
	}
	while (--a->bot >= 0)
		rra(a, "rra\n");
	while (--b->bot >= -1)
		rrb(b, "rrb\n");
	pa(b, a, "pa\n");
}
