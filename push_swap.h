/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:14:55 by mdaifi            #+#    #+#             */
/*   Updated: 2021/04/26 16:09:06 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct	s_push_swap
{
	int		*t;
	int		size;
	int		i;
}				t_push_swap;


int		find_median(t_push_swap *tab);
void	sa(t_push_swap *a);
void	sb(t_push_swap *b);
void	ss(t_push_swap *a, t_push_swap *b);
void	ra(t_push_swap *a);
void	rb(t_push_swap *b);
void	rra(t_push_swap *a);
void	rrb(t_push_swap *b);
void	rrr(t_push_swap *a, t_push_swap *b);
void	pb(t_push_swap *a, t_push_swap *b);
void	pa(t_push_swap *b, t_push_swap *a);
void	push_swap(t_push_swap *a, t_push_swap *b, t_push_swap *tmp);
void	print_table(t_push_swap *tab);