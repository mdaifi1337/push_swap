/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:46:11 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/11 15:35:55 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	invalid_input(t_push_swap *a, char **str)
{
	if (check_actions_errors(*str))
	{
		free(*str);
		free(a->t);
		exit(1);
	}
}

void	check_man_input(t_push_swap *a, char **str, char **ch)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while ((*ch)[++i])
	{
		if ((*ch)[i] == '\n')
			k++;
	}
	if (k == 1)
	{
		if (check_actions_errors(*ch))
		{
			free(*ch);
			free(*str);
			free(a->t);
			exit(1);
		}
	}
}

void	action_to_exec(t_push_swap *a, t_push_swap *b, char *str)
{
	if (!ft_strncmp(str, "ra", 3))
		ra(a, "KO");
	else if (!ft_strncmp(str, "rb", 3))
		rb(b, "KO");
	else if (!ft_strncmp(str, "rr", 3))
		rr(a, b, "KO");
	else if (!ft_strncmp(str, "pa", 3))
		pa(b, a, "KO");
	else if (!ft_strncmp(str, "pb", 3))
		pb(a, b, "KO");
	else if (!ft_strncmp(str, "sa", 3))
		sa(a, "KO");
	else if (!ft_strncmp(str, "sb", 3))
		sb(b, "KO");
	else if (!ft_strncmp(str, "ss", 3))
		ss(a, b, "KO");
	else if (!ft_strncmp(str, "rra", 4))
		rra(a, "KO");
	else if (!ft_strncmp(str, "rrb", 4))
		rrb(b, "KO");
	else if (!ft_strncmp(str, "rrr", 4))
		rrr(a, b, "KO");
}

void	join_actions(char **str, char *ch, int res)
{
	char	*tmp;

	if (res > 0)
	{
		tmp = *str;
		*str = ft_strjoin(*str, ch);
		free(tmp);
	}
}
