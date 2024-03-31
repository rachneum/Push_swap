/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:21:37 by rachou            #+#    #+#             */
/*   Updated: 2024/03/31 18:05:52 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_stack *a)
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
