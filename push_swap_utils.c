/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:11:05 by rachou            #+#    #+#             */
/*   Updated: 2024/03/26 09:57:49 by rachou           ###   ########.fr       */
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
int	stack_len(t_stack_node *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}
/*
t_stack	*find_min(t_stack *stack)//Recherche une pile et renvoie le noeud avec le plus petit nombre.
{
	long	min;//Pour stocker la plus petite valeur jusqu'à présent.
	t_stack	*min_node;//Pour stocker un pointeur pointant vers le plus petit nombre.

	if (!stack)
		return (NULL);
	min = LONG_MAX;//Attribue à la plus petite valeur jusqu'à présent, l'entier long maximum
	while (stack)
	{
		if (stack->nbr < min) //Check if the current node value is smaller than the smallest so far
		{
			min = stack->nbr; //If so, update the smallest number so far
			min_node = stack; //Set the pointer to point to the node with the smallest number so far
		}
		stack = stack->next; //Move to the next node for processing
	}
	return (min_node); 
}

t_stack	*find_max(t_stack *stack) //Define a function that searches a stack and returns the node with the biggest number
{
	long			max; //To store the biggest value so far
	t_stack	*max_node; //To store a pointer that points to the biggest number

	if (!stack)
		return (NULL);
	max = LONG_MIN; //Assign to the biggest value so far, the max long integer
	while (stack) //Loop until the end of the stack is reached
	{
		if (stack->nbr > max) //Check if the current node value is smaller than the biggest so far
		{
			max = stack->nbr; //If so, update the biggest number so far
			max_node = stack; //Set the pointer to point to the node with the biggest number so far
		}
		stack = stack->next; //Move to the next node for processing
	}
	return (max_node);
}*/