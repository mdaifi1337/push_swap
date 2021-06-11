/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:13:01 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/11 16:01:36 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push_swap *a, char *str)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = a->t[i];
	while (i < a->size)
	{
		a->t[i] = a->t[i + 1];
		i++;
	}
	a->t[i - 1] = tmp;
	if (!ft_strncmp(str, "ra\n", 4))
		write(1, str, 3);
}

void	rb(t_push_swap *b, char *str)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = b->t[i];
	while (i < b->size)
	{
		b->t[i] = b->t[i + 1];
		i++;
	}
	b->t[i - 1] = tmp;
	if (!ft_strncmp(str, "rb\n", 4))
		write(1, str, 3);
}

void	rra(t_push_swap *a, char *str)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < a->size)
		i++;
	i--;
	tmp = a->t[i];
	while (i > 0)
	{
		a->t[i] = a->t[i - 1];
		i--;
	}
	a->t[0] = tmp;
	if (!ft_strncmp(str, "rra\n", 5))
		write(1, str, 4);
}

void	rrb(t_push_swap *b, char *str)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < b->size)
		i++;
	i--;
	tmp = b->t[i];
	while (i > 0)
	{
		b->t[i] = b->t[i - 1];
		i--;
	}
	b->t[0] = tmp;
	if (!ft_strncmp(str, "rrb\n", 5))
		write(1, str, 4);
}
