/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:19:45 by ahusic            #+#    #+#             */
/*   Updated: 2024/05/31 16:15:41 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a, int op)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = *stack_a;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last != NULL)
		second_last->next = NULL;
	last->next = *stack_a;
	last->prev = NULL;
	(*stack_a)->prev = last;
	*stack_a = last;
	if (op == SINGLE_OP)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, int op)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = *stack_b;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last != NULL)
		second_last->next = NULL;
	last->next = *stack_b;
	last->prev = NULL;
	(*stack_b)->prev = last;
	*stack_b = last;
	if (op == SINGLE_OP)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int op)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (op == DOUBLE_OP)
		ft_printf("rrr\n");
}
