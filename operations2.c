/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:17:39 by ahusic            #+#    #+#             */
/*   Updated: 2024/05/31 16:15:20 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a, int op)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
	if (op == SINGLE_OP)
		ft_printf("ra\n");
}

void	rb(t_stack **stack_b, int op)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
	if (op == SINGLE_OP)
		ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, int op)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (op == DOUBLE_OP)
		ft_printf("rr\n");
}
