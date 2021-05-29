/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:14:55 by mdaifi            #+#    #+#             */
/*   Updated: 2021/05/26 18:05:13 by mdaifi           ###   ########.fr       */
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
	int		top;
	int		bot;
	int		count;
}				t_push_swap;


int		find_median(t_push_swap *tab, int fisrt, int last);
void	sa(t_push_swap *a);
void	sb(t_push_swap *b);
void	ss(t_push_swap *a, t_push_swap *b);
void	ra(t_push_swap *a, char *str);
void	rb(t_push_swap *b, char *str);
void	rra(t_push_swap *a, char *str);
void	rrb(t_push_swap *b, char *str);
void	rr(t_push_swap *a, t_push_swap *b);
void	rrr(t_push_swap *a, t_push_swap *b);
void	pb(t_push_swap *a, t_push_swap *b);
void	pa(t_push_swap *b, t_push_swap *a);
void	push_swap(t_push_swap *a, t_push_swap *b, t_push_swap *tmp);
void	print_table(t_push_swap *a, t_push_swap *b);