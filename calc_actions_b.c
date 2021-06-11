/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_actions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:37:20 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/07 18:23:56 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_acts_top_b(int nbr1, int nbr2, t_push_swap *a, t_push_swap *b)
{
	if (nbr1 == -1)
	{
		a->bot = 1;
		a->top = 0;
	}
	else if (nbr1 <= 0 && abs(nbr1) <= nbr2)
	{
		a->bot = nbr2;
		a->top = 0;
	}
	else if (nbr1 < 0 && b->top == 0 && a->top)
		a->bot = nbr2;
	else if (nbr1 > 0)
	{
		a->top = nbr1;
		a->bot = 0;
	}
}

void	calc_acts_bot_b(int nbr, int *res, t_push_swap *a, t_push_swap *b)
{
	if (b->size - b->second == 0)
		res[1] = 1;
	if (nbr == -1)
	{
		a->bot = 1;
		a->top = 0;
	}
	else if (nbr <= 0 && abs(nbr) <= res[0])
	{
		a->bot = res[0];
		a->top = 0;
	}
	else if (nbr < 0 && b->top == 0)
		a->bot = res[0];
	else if (nbr > 0)
	{
		a->top = nbr;
		a->bot = 0;
	}
}

int	*search_top_b(t_push_swap *a, t_push_swap *b, int *tab)
{
	int	*res;

	res = (int *)malloc(sizeof(int) * 2);
	res[0] = abs(tab[0]);
	res[1] = abs(tab[1]);
	calc_acts_top_b(tab[0], res[0], a, b);
	b->top = abs(tab[1]);
	b->bot = 0;
	return (res);
}

int	*search_bot_b(t_push_swap *a, t_push_swap *b, int *tab, int i)
{
	int	*res;

	res = (int *)malloc(sizeof(int) * 2);
	res[0] = abs(tab[0]);
	res[1] = abs(tab[1]);
	calc_acts_bot_b(tab[0], res, a, b);
	b->top = 0;
	b->bot = abs(tab[1]);
	if (i == 0)
		b->bot = -1;
	return (res);
}

void	ft_free(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
