/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:18:27 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/03 19:23:42 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_table(t_push_swap *a, t_push_swap *b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("---------------------------------------------------\n");
	if (a->size >= b->size)
	{
		while (i < a->size)
		{
			printf("%d\t", a->t[i]);
			if (a->size - i <= b->size && j < b->size && b->size)
			{
				printf("%d\n", b->t[j]);
				j++;
			}
			else
				printf("\n");
			i++;
		}
	}
	else
	{
		while (i < b->size)
		{
			if (b->size - i <= a->size && j < a->size)
			{
				printf("%d\t", a->t[j]);
				printf("%d\n", b->t[i]);
				j++;
			}
			else
			{
				printf("\t");
				printf("%d\n", b->t[i]);
			}
			i++;
		}
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
	int			asize;
	int			bsize;
	int			i;

	// for (size_t x = 0; x < 2;)
	// {
	// 	x = 0;
	// }
	
	a.size = argc - 1;
	b.size = 0;
	a.t = (int *)malloc(sizeof(int) * a.size);
	// b.t = (int *)malloc(sizeof(int) * b.size);
	i = -1;
	// while (++i < b.size)
	// 	b.t[i] = 0;
	// b.i = a.size;
	i = 0;
	while (i < a.size)
	{
		a.t[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	// sort_table(&tmp);
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
	// sa(&a);
	// rra(&a, "rra\n");
	// ra(&a);
	// print_table(&a, &b);
	// pb(&a, &b);
	// pb(&a, &b);
	// pb(&a, &b);
	// // pb(&a, &b);
	// // printf("Stack a : \n");
	// print_table(&a, &b);
	// i = 0;
	// 	while (i < b.size)
	// 	{
	// 		printf("b->t[%d] : %d\n", i, b.t[i]);
	// 		i++;
	// 	}
	// print_table(&a, &b);
	push_swap(&a, &b);
	// print_table(&a, &b);
	return (0);
}