/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:18:27 by mdaifi            #+#    #+#             */
/*   Updated: 2021/05/01 15:37:11 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_table(t_push_swap *a, t_push_swap *b)
{
	int	i;

	i = 0;
	printf("---------------------------------------------------\n");
	while (i < a->size)
	{
		// if (t->t[i] != 0)
			printf("%d\t%d\n", a->t[i], b->t[i]);
		i++;
	}
	printf("-\t-\n");
	printf("a\tb\n");
	printf("---------------------------------------------------\n");
}

void	sort_table(t_push_swap *t)
{
	int	i;
	int	j;
	int	min;
	int tmp;

	i = 0;
	while (i < t->size - 1)
	{
		min = i;
		j = i + 1;
		while (j < t->size)
		{
			if (t->t[j] < t->t[min])
				min = j;
			j++;
		}
		tmp = t->t[min];
		t->t[min] = t->t[i];
		t->t[i] = tmp;
		i++;
	}
}

int	find_median(t_push_swap *t, int first, int last)
{
	int	median;
	int	half_size;
	int	size;

	size = first + last;
	if (size % 2 == 0)
		size++;
	half_size = size / 2;
	return (t->t[half_size]);
}

int	main(int argc, char *argv[])
{
	t_push_swap	a;
	t_push_swap	b;
	t_push_swap	tmp;
	int			asize;
	int			bsize;
	int			i;

	a.size = argc - 1;
	b.size = a.size;
	tmp.size = a.size;
	a.t = (int *)malloc(sizeof(int) * a.size);
	b.t = (int *)malloc(sizeof(int) * b.size);
	tmp.t = (int *)malloc(sizeof(int) * tmp.size);
	i = -1;
	while (++i < b.size)
		b.t[i] = 0;
	a.i = 0;
	b.i = a.size;
	i = 0;
	while (i < a.size)
	{
		a.t[i] = ft_atoi(argv[i + 1]);
		tmp.t[i] = a.t[i];
		i++;
	}
	sort_table(&tmp);
	// print_table(&tmp);
	// printf("Median : %d\n", find_median(&tmp));
	// pb(&a, &b);
	// pb(&a, &b);
	// pb(&a, &b);
	// pb(&a, &b);
	// printf("Stack a : \n");
	// print_table(&a);
	// printf("Stack b : \n");
	// print_table(&b);
	// printf("---------------------------------------------------\n");
	// printf("After push to a : \n");
	// ra(&a);
	// ra(&a);
	// pa(&b, &a);
	// pa(&b, &a);
	// printf("Stack a : \n");
	// print_table(&a, &b);
	push_swap(&a, &b, &tmp);
	// print_table(&a, &b);
	return (0);
}