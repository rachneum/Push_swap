/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:13:28 by rachou            #+#    #+#             */
/*   Updated: 2024/04/05 16:06:31 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)//?
{

}

static void	move_a_to_b(t_stack **a, t_stack **b)
{

}

static void	move_b_to_a(t_stack **a, t_stack **b)
{

}

void	min_on_top(t_stack **a)
{

}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len_a;

	if (len_a-- > 3)
		pb(b, a);
	if (len_a-- > 3)
		pb(b, a);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	min_on_top(a);
}
