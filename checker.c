/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:04:28 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/11 16:02:03 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_actions_errors(char *str)
{
	int	i;
	int	ok;

	i = -1;
	ok = 0;
	while (str[++i] && !ok)
	{
		if (str[i] == 'r' && (str[i + 1] == 'a' || str[i + 1] == 'b'
				|| str[i + 1] == 'r') && str[i + 2] == '\n')
			i += 2;
		else if (str[i] == 'p' && (str[i + 1] == 'a' || str[i + 1] == 'b')
			&& str[i + 2] == '\n')
			i += 2;
		else if (str[i] == 's' && (str[i + 1] == 'a' || str[i + 1] == 'b'
				|| str[i + 1] == 's') && str[i + 2] == '\n')
			i += 2;
		else if (str[i] == 'r' && str[i + 1] == 'r' && (str[i + 2] == 'a'
				|| str[i + 2] == 'b' || str[i + 2] == 'r') && str[i + 3] == '\n')
			i += 3;
		else
			ok = 1;
	}
	if (ok == 1)
		write (2, "Error\n", 7);
	return (ok);
}

void	exec_actions(t_push_swap *a, t_push_swap *b, char *str)
{
	char	**tab;
	int		i;

	tab = ft_split(str, '\n');
	i = -1;
	while (tab[++i])
		action_to_exec(a, b, tab[i]);
	ft_free(tab);
}

void	checker(t_push_swap *a, t_push_swap *b)
{
	char	*ch;
	char	*str;
	char	*tmp;
	int		res;
	int		buff;

	res = 1;
	buff = 6000;
	ch = (char *)malloc(sizeof(char) * buff);
	if (!str)
		return ;
	str = ft_strdup("");
	while (res > 0)
	{
		ft_bzero(ch, buff);
		res = read(0, ch, buff);
		check_man_input(a, &str, &ch);
		join_actions(&str, ch, res);
	}
	invalid_input(a, &str);
	exec_actions(a, b, str);
	free(str);
	free(ch);
}

int	main(int argc, char *argv[])
{
	t_push_swap	a;
	t_push_swap	b;
	int			i;

	a.size = argc - 1;
	b.size = 0;
	if (argc == 2)
		two_args(&a, argv);
	else
	{
		a.t = (int *)malloc(sizeof(int) * a.size);
		i = -1;
		while (++i < a.size)
			a.t[i] = ft_atoi(argv[i + 1]);
		check_input_vals(argv + 1, &a);
	}
	checker(&a, &b);
	if (check_order(&a))
		write(1, "KO\n", 4);
	else
		write(1, "OK\n", 4);
	free(a.t);
	return (0);
}
