/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:27:47 by raneuman          #+#    #+#             */
/*   Updated: 2024/04/11 13:27:48 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
	int				value;
	int				index;
	int				push_price;//
	bool			median;
	bool			cheapest;//
}					t_stack;

char	**ft_split(char const *s, char c);

t_stack	*find_last_node(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);//

int		main(int argc, char **argv);
int		syntax_error(char *str_nb);
int		error_duplicate(t_stack *a, int nb);
int		stack_len(t_stack *stack);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	sa(t_stack	**a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **a);
void	stack_init(t_stack **a, char **argv);
void	sort_three(t_stack **a);
void	sort_stack(t_stack **a, t_stack **b);//
void	set_index(t_stack *stack);
void	init_nodes_a(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);//
void	init_nodes_b(t_stack *a, t_stack *b);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);//
void	min_on_top(t_stack **a);//

bool	stack_sorted(t_stack *stack);

#endif