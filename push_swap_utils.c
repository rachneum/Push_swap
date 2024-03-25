/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:11:05 by rachou            #+#    #+#             */
/*   Updated: 2024/03/25 10:37:18 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_last_node(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)// Boucle jusqu'à ce que la fin de la pile soit atteinte.
        stack = stack->next;
    return (stack);
}
