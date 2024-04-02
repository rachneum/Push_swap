/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:59:59 by rachou            #+#    #+#             */
/*   Updated: 2024/04/02 14:06:50 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    stack_sorted(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack-> next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack sort_stack(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if ((len_a > 3) && !stack_sorted(*a))
	{
		pb(&b, &a);
		len_a--;
	}
	if ((len_a > 3) && !stack_sorted(*a))

}

void    sort_three(t_stack **a)
{
    t_stack *biggest_node;
    t_stack *smallest_node;

    if (!a)
        return ;
    if (stack_len(a) == 3)
    {
        biggest_node = find_max(a);
        smallest_node = find_min(a);
        while (a)
        {
            /*if (a->value == biggest_node)
                ra(a);
            if (((a->value > smallest_node) && (a->value < biggest_node)) && (a->next->value == smallest_node))
                sa(a);
            a = a->next;
            if (a->value == smallest_node)*/
        }
    }
}
