/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:49:34 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/11 15:41:58 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_inc_size(t_push_swap *st, int nbr)
{
	int	i;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * st->size);
	if (!tmp)
		return ;
	i = -1;
	while (++i < st->size)
		tmp[i] = st->t[i];
	st->size += 1;
	free(st->t);
	st->t = (int *)malloc(sizeof(int) * st->size);
	if (!st->t)
	{
		free(tmp);
		return ;
	}
	st->t[0] = nbr;
	i = 0;
	while (++i < st->size)
		st->t[i] = tmp[i - 1];
	free(tmp);
}

static void	ft_dec_size(t_push_swap *st)
{
	int	i;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * st->size - 1);
	if (!tmp)
		return ;
	i = -1;
	while (++i < st->size)
		tmp[i] = st->t[i + 1];
	st->size -= 1;
	free(st->t);
	st->t = (int *)malloc(sizeof(int) * st->size);
	if (!st->t)
	{
		free(tmp);
		return ;
	}
	i = -1;
	while (++i < st->size)
		st->t[i] = tmp[i];
	free(tmp);
}

void	pa(t_push_swap *b, t_push_swap *a, char *str)
{
	if (b->size > 0)
	{
		ft_inc_size(a, b->t[0]);
		ft_dec_size(b);
		if (!ft_strncmp(str, "pa\n", 4))
			write(1, "pa\n", 3);
	}
	if (b->size == 0)
		free(b->t);
}

void	pb(t_push_swap *a, t_push_swap *b, char *str)
{
	if (!b->size)
	{
		b->t = (int *)malloc(sizeof(int));
		if (!b->t)
			return ;
	}
	if (a->size > 0)
	{
		ft_inc_size(b, a->t[0]);
		ft_dec_size(a);
	}
	if (!ft_strncmp(str, "pb\n", 4))
		write(1, "pb\n", 3);
}
