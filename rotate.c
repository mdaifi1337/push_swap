/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:13:01 by mdaifi            #+#    #+#             */
/*   Updated: 2021/05/25 15:40:27 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push_swap *a, int nbr)
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
	if (nbr == 1)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_push_swap *b, int nbr)
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
	if (nbr == 1)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_push_swap *a, t_push_swap *b)
{
	ra(a, 0);
	rb(b, 0);
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_push_swap *a, int nbr)
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
	if (nbr == 1)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_push_swap *b, int nbr)
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
	if (nbr == 1)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_push_swap *a, t_push_swap *b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_putstr_fd("rrr\n", 1);
}
