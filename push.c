/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:49:34 by mdaifi            #+#    #+#             */
/*   Updated: 2021/04/27 15:28:08 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_push_swap *b, t_push_swap *a)
{
	a->i--;
	a->t[a->i] = b->t[b->i];
	b->t[b->i] = 0;
	b->i++;
	printf("pa\n");
}

void	pb(t_push_swap *a, t_push_swap *b)
{
	b->i--;
	b->t[b->i] = a->t[a->i];
	a->t[a->i] = 0;
	a->i++;
	printf("pb\n");
}