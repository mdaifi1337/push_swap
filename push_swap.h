/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:14:55 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/11 16:57:42 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_push_swap
{
	int	*t;
	int	size;
	int	top;
	int	bot;
	int	second;
}				t_push_swap;

int		min_val(int *t, int len);
int		max_val(int *t, int len);
int		check_order(t_push_swap *t);
int		check_if_not_nbr(char **tab);
int		check_for_doubles(t_push_swap *st);
int		check_max_min_int(char **tab);
int		count_ops(int pos_a, int pos_b);
int		check_actions_errors(char *str);
int		in_lis(int nbr, int *lis_elm, int size);
int		*longest_inc_seq(t_push_swap *a, int *max_lis);
int		*search_top_b(t_push_swap *a, t_push_swap *b, int *tab);
int		*search_bot_b(t_push_swap *a, t_push_swap *b, int *tab, int i);
void	ft_free(char **tab);
void	sa(t_push_swap *a, char *str);
void	sb(t_push_swap *b, char *str);
void	ss(t_push_swap *a, t_push_swap *b, char *str);
void	ra(t_push_swap *a, char *str);
void	rb(t_push_swap *b, char *str);
void	rra(t_push_swap *a, char *str);
void	rrb(t_push_swap *b, char *str);
void	rr(t_push_swap *a, t_push_swap *b, char *str);
void	rrr(t_push_swap *a, t_push_swap *b, char *str);
void	pb(t_push_swap *a, t_push_swap *b, char *str);
void	pa(t_push_swap *b, t_push_swap *a, char *str);
void	rotate_a(t_push_swap *a);
void	rotate_b(t_push_swap *b);
void	check_input_vals(char **tab, t_push_swap *st);
void	stack_of_three(t_push_swap *a);
void	push_swap(char **tab, int size);
void	two_args(t_push_swap *a, char **tab);
void	find_best(t_push_swap *a, t_push_swap *b);
void	init_vars(t_push_swap *a, t_push_swap *b);
void	join_actions(char **str, char *ch, int res);
void	smart_rotate_top(t_push_swap *a, t_push_swap *b);
void	smart_rotate_bot(t_push_swap *a, t_push_swap *b);
void	invalid_input(t_push_swap *a, char **str);
void	check_man_input(t_push_swap *a, char **str, char **ch);
void	action_to_exec(t_push_swap *a, t_push_swap *b, char *str);
void	calc_acts_top_b(int nbr1, int nbr2, t_push_swap *a, t_push_swap *b);
void	calc_acts_bot_b(int nbr, int *res, t_push_swap *a, t_push_swap *b);

#endif
