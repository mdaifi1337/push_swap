/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:18:27 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/11 15:19:03 by mdaifi           ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	push_swap(argv, argc);
	return (0);
}
