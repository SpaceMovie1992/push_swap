/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:08:44 by ahusic            #+#    #+#             */
/*   Updated: 2024/06/05 17:22:59 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/inc/libft.h"
# include <limits.h>
# include <stdbool.h>

# define SINGLE_OP 1
# define DOUBLE_OP 0

typedef struct s_stack
{
	int				index;
	long			value;
	long			num_moves;
	bool			over_middle;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}						t_stack;

//error handling
void	if_error(void);
void	free_stack(t_stack *stack, bool error);
void	free_str(char **str);

//stack operations
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack *stack_a, int op);
void	sb(t_stack *stack_b, int op);
void	ss(t_stack **stack_a, t_stack **stack_b, int op);
void	ra(t_stack **stack_a, int op);
void	rb(t_stack **stack_b, int op);
void	rr(t_stack **stack_a, t_stack **stack_b, int op);
void	rra(t_stack **stack_a, int op);
void	rrb(t_stack **stack_b, int op);
void	rrr(t_stack **stack_a, t_stack **stack_b, int op);

//stack utilities
int		is_digit(const char *str, bool *error);
void	check_signs(const char *str, bool *error);
int		stack_size(t_stack *stack);
int		atoi2(const char *str, bool *error);
void	index_init(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*last_node(t_stack *stack);
void	add_node(t_stack **stack, int value);

//parsing and sorting
void	dup_check(t_stack *stack);
int		is_sorted(t_stack *stack);
t_stack	*arg_parse(int argc, char **argv, bool *error);
t_stack	*find_cheapest(t_stack *stack);
void	sort_3(t_stack **stack);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	final_sort(t_stack **stack_a);
void	big_sort(t_stack **stack_a, t_stack **stack_b);

//cost and target
void	pa_cost(t_stack *stack_a, t_stack *stack_b);
void	target_a(t_stack *stack_a, t_stack *stack_b);
void	pa_prep(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);
void	push_to_a(t_stack **stack_a, t_stack **stack_b);
void	pb_cost(t_stack *stack_a, t_stack *stack_b);
void	target_b(t_stack *stack_a, t_stack *stack_b);
void	pb_prep(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);
void	push_to_b(t_stack **stack_a, t_stack **stack_b);

int		main(int argc, char **argv);


#endif
