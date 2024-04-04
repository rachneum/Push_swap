#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>//Bibli me permettant d'utiliser LONG_MIN et LON_MAX.
# include <stdbool.h>
# include "Libft/libft.h"

typedef struct s_stack
{
    int             value;
    int             index;
    int             push_cost;
	bool			median;
    struct s_stack  *next;
    struct s_stack  *prev;
    struct s_stack  *target_node;
}                   t_stack;

int	error_syntax(char	*str_nb);
int	error_duplicate(t_stack *a, int nb);
int	stack_len(t_stack *stack);
int	main(int argc, char **argv);

void	free_stack(t_stack **stack);
void	free_errors(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	sa(t_stack	**a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	current_index(t_stack *stack);
//void	sort_stack(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	stack_init(t_stack **a, char **argv);

t_stack	*find_last_node(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);

bool	stack_sorted(t_stack *stack);

#endif