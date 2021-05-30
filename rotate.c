/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:13:01 by mdaifi            #+#    #+#             */
/*   Updated: 2021/05/30 16:24:34 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push_swap *a, char *str)
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
	if (!ft_strncmp(str, "ra\n", 4))
		printf("%s", str);
		// write(1, str, 3);
}

void	rb(t_push_swap *b, char *str)
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
	if (!ft_strncmp(str, "rb\n", 4))
		printf("%s", str);
		// write(1, str, 3);
}

void	rr(t_push_swap *a, t_push_swap *b)
{
	ra(a, "KO\n");
	rb(b, "KO\n");
	printf("rr\n");
	// write(1, "rr\n", 3);
}

void	rra(t_push_swap *a, char *str)
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
	if (!ft_strncmp(str, "rra\n", 5))
		printf("%s", str);
		// write(1, str, 4);
}

void	rrb(t_push_swap *b, char *str)
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
	if (!ft_strncmp(str, "rrb\n", 5))
		printf("%s", str);
		// write(1, str, 4);
}

void	rrr(t_push_swap *a, t_push_swap *b)
{
	rra(a, "KO\n");
	rrb(b, "KO\n");
	printf("rrr\n");
	write(1, "rrr\n", 4);
}
