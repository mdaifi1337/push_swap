/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:40:45 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/06 18:56:19 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_push_swap *a)
{
	if (a->top)
	{
		while (--a->top >= 0)
			ra(a, "ra\n");
	}
	else if (a->bot)
	{
		while (--a->bot >= 0)
			rra(a, "rra\n");
	}
}

void	rotate_b(t_push_swap *b)
{
	if (b->top)
	{
		while (--b->top >= 0)
			rb(b, "rb\n");
	}
	else if (b->bot)
	{
		if (b->bot == -1)
			b->bot = 0;
		while (--b->bot >= -1)
			rrb(b, "rrb\n");
	}
}
