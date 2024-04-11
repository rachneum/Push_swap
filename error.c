/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:53:22 by rachou            #+#    #+#             */
/*   Updated: 2024/04/08 15:36:25 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_error(char *str_nb)
{
	if (!(*str_nb == '+' || *str_nb == '-' || (*str_nb >= '0' && *str_nb <= '9')))
		return (1);
	if ((*str_nb == '+' || *str_nb == '-') && !(str_nb[1] >= '0' && str_nb[1] <= '9'))
		return (1);
	while (*++str_nb)
	{
		if (!(*str_nb >= '0' && *str_nb <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack *a, int nb)
{
	if(!a)
		return (0);
	while (a)
	{
		if (a->value == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;

		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack **a)
{
	free_stack(a);
	write(1, "Error\n", 6);
	exit(1);
}
