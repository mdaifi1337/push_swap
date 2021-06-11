/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_of_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:45:36 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/06 18:56:44 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_of_three(t_push_swap *a)
{
	if (a->t[0] > a->t[1] && a->t[0] > a->t[a->size - 1])
	{
		if (a->t[1] > a->t[a->size - 1])
		{
			sa(a, "sa\n");
			rra(a, "rra\n");
		}
		else
			ra(a, "ra\n");
	}
	else if (a->t[0] > a->t[1] && a->t[0] < a->t[a->size - 1])
		sa(a, "sa\n");
	else if (a->t[0] < a->t[1] && a->t[0] > a->t[a->size - 1])
		rra(a, "rra\n");
	else if (a->t[0] < a->t[1] && a->t[0] < a->t[a->size - 1])
	{
		if (a->t[1] > a->t[a->size - 1])
		{
			sa(a, "sa\n");
			ra(a, "ra\n");
		}
	}
}
