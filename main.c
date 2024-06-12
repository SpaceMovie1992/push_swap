/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:05:37 by ahusic            #+#    #+#             */
/*   Updated: 2024/06/05 18:04:02 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	bool	error;

	stack_a = NULL;
	stack_b = NULL;
	error = false;
	if (argc == 1)
		return (0);
	else
		stack_a = arg_parse(argc, argv, &error);
	dup_check(stack_a);
	if (!is_sorted(stack_a))
	{
		if (stack_size(stack_a) == 2)
			sa(stack_a, SINGLE_OP);
		else if (stack_size(stack_a) == 3)
			sort_3(&stack_a);
		else if (stack_size(stack_a) == 5)
			sort_5(&stack_a, &stack_b);
		else
			big_sort(&stack_a, &stack_b);
	}
	free_stack(stack_a, false);
	free_stack(stack_b, false);
}
