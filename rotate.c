/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:13:01 by mdaifi            #+#    #+#             */
/*   Updated: 2021/04/27 15:28:07 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push_swap *a)
{
	int	i;
	int	tmp;
	int	tmp2;

	i = a->i;
	tmp = a->t[i];
	while (i < a->size)
	{
		a->t[i] = a->t[i + 1];
		i++;
	}
	a->t[i - 1] = tmp;
	printf("ra\n");
}

void	rb(t_push_swap *b)
{
	int	i;
	int	tmp;
	int	tmp2;

	i = b->i;
	tmp = b->t[i];
	while (i < b->size)
	{
		b->t[i] = b->t[i + 1];
		i++;
	}
	b->t[i - 1] = tmp;
	printf("rb\n");
}

void	rra(t_push_swap *a)
{
	int	tmp;
	int	tmp2;
	int	i;

	i = a->i;
	while (i < a->size)
		i++;
	i--;
	tmp = a->t[i];
	while (i > a->i)
	{
		a->t[i] = a->t[i - 1];
		i--;
	}
	a->t[a->i] = tmp;
	printf("rra\n");
}

void	rrb(t_push_swap *b)
{
	int	tmp;
	int	tmp2;
	int	i;

	i = b->i;
	while (i < b->size)
		i++;
	i--;
	tmp = b->t[i];
	while (i > b->i)
	{
		b->t[i] = b->t[i - 1];
		i--;
	}
	b->t[b->i] = tmp;
	printf("rrb\n");
}

void	rrr(t_push_swap *a, t_push_swap *b)
{
	rra(a);
	rrb(b);
}
