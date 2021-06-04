/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:09:40 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/02 16:33:44 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push_swap *a)
{
	int	tmp;

	tmp = a->t[0];
	a->t[0] = a->t[1];
	a->t[1] = tmp;
	// write (1, "sa\n", 3);
	printf("sa\n");
}

void	sb(t_push_swap *b)
{
	int	tmp;

	tmp = b->t[0];
	b->t[0] = b->t[1];
	b->t[1] = tmp;
	// write (1, "sb\n", 3);
	printf("sb\n");
}

void	ss(t_push_swap *a, t_push_swap *b)
{
	sa(a);
	sb(b);
}