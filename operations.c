/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:07:21 by ahusic            #+#    #+#             */
/*   Updated: 2024/06/05 17:05:36 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b != NULL)
		(*stack_b)->prev = NULL;
	temp->next = *stack_a;
	if (*stack_a != NULL)
		(*stack_a)->prev = temp;
	*stack_a = temp;
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a != NULL)
		(*stack_a)->prev = NULL;
	temp->next = *stack_b;
	if (*stack_b != NULL)
		(*stack_b)->prev = temp;
	*stack_b = temp;
	ft_printf("pb\n");
}

void	sa(t_stack *stack_a, int op)
{
	int	tmp;

	if (stack_a == NULL || stack_a->next == NULL)
		return ;
	tmp = stack_a->value;
	stack_a->value = stack_a->next->value;
	stack_a->next->value = tmp;
	if (op == SINGLE_OP)
		ft_printf("sa\n");
}

void	sb(t_stack *stack_b, int op)
{
	int	tmp;

	if (stack_b == NULL || stack_b->next == NULL)
		return ;
	tmp = stack_b->value;
	stack_b->value = stack_b->next->value;
	stack_b->next->value = tmp;
	if (op == SINGLE_OP)
		ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b, int op)
{
	sa(*stack_a, 0);
	sb(*stack_b, 0);
	if (op == DOUBLE_OP)
		ft_printf("ss\n");
}
