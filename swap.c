/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:09:40 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/12 15:35:26 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push_swap *a, char *str)
{
	int	tmp;

	if (a->size > 1)
	{
		tmp = a->t[0];
		a->t[0] = a->t[1];
		a->t[1] = tmp;
		if (!ft_strncmp(str, "sa\n", 4))
			write (1, "sa\n", 3);
	}
}

void	sb(t_push_swap *b, char *str)
{
	int	tmp;

	if (b->size > 1)
	{
		tmp = b->t[0];
		b->t[0] = b->t[1];
		b->t[1] = tmp;
		if (!ft_strncmp(str, "sb\n", 4))
			write (1, "sb\n", 3);
	}
}

void	ss(t_push_swap *a, t_push_swap *b, char *str)
{
	if (a->size > 1 && b->size > 1)
	{
		sa(a, "KO");
		sb(b, "KO");
		if (!ft_strncmp(str, "ss\n", 4))
			write(1, "ss\n", 3);
	}
}
