/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:09:40 by mdaifi            #+#    #+#             */
/*   Updated: 2021/04/27 15:28:10 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push_swap *a)
{
	int	tmp;

	tmp = a->t[a->i];
	a->t[a->i] = a->t[a->i + 1];
	a->t[a->i + 1] = tmp;
	printf("sa\n");
}

void	sb(t_push_swap *b)
{
	int	tmp;

	tmp = b->t[b->i];
	b->t[b->i] = b->t[b->i + 1];
	b->t[b->i + 1] = tmp;
	printf("sb\n");
}

void	ss(t_push_swap *a, t_push_swap *b)
{
	sa(a);
	sb(b);
}