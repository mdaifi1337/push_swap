/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:49:34 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/03 19:27:03 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_push_swap *b, t_push_swap *a)
{
	int	i;
	int	*tmp;
	int	*tab;

	tmp = (int *)malloc(sizeof(int) * a->size);
	i = -1;
	while (++i < a->size)
		tmp[i] = a->t[i];
	i = 0;
	a->size += 1;
	free(a->t);
	a->t = (int *)malloc(sizeof(int) * a->size);
	// b->t[0] = a->t[0]; add after copying values to new allocated b
	a->t[0] = b->t[0];
	i = 1;
	while (i < a->size)
	{
		a->t[i] = tmp[i - 1];
		i++;
	}
	free(tmp);
	tmp = (int *)malloc(sizeof(int) * b->size - 1);
	i = 0;
	while (i < b->size)
	{
		tmp[i] = b->t[i + 1];
		i++;
	}
	i = 0;
	b->size -= 1;
	free(b->t);
	b->t = (int *)malloc(sizeof(int) * b->size);
	// b->t[0] = a->t[0]; add after copying values to new allocated b
	i = 0;
	while (i < b->size)
	{
		b->t[i] = tmp[i];
		i++;
	}
	free(tmp);
	printf("pa\n");
}

void	pb(t_push_swap *a, t_push_swap *b)
{
	int	i;
	int	*tmp;
	int	*tab;

	if (!b->size)
	{
		b->t = (int *)malloc(sizeof(int));
		b->t[0] = a->t[0];
		b->size++;
	}
	else
	{
		tmp = (int *)malloc(sizeof(int) * b->size);
		i = -1;
		while (++i < b->size)
			tmp[i] = b->t[i];
		i = 0;
		b->size += 1;
		free(b->t);
		b->t = (int *)malloc(sizeof(int) * b->size);
		// b->t[0] = a->t[0]; add after copying valyes to new allocated b
		b->t[0] = a->t[0];
		i = 1;
		while (i < b->size)
		{
			b->t[i] = tmp[i - 1];
			i++;
		}
		free(tmp);
	}
	tmp = (int *)malloc(sizeof(int) * a->size - 1);
	i = 0;
	while (i < a->size)
	{
		tmp[i] = a->t[i + 1];
		i++;
	}
	i = 0;
	a->size -= 1;
	free(a->t);
	a->t = (int *)malloc(sizeof(int) * a->size);
	// b->t[0] = a->t[0]; add after copying valyes to new allocated b
	i = 0;
	while (i < a->size)
	{
		a->t[i] = tmp[i];
		i++;
	}
	free(tmp);
	printf("pb\n");
	// write(1, "pb\n", 3);
}