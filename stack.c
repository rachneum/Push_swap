/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:31:04 by rachou            #+#    #+#             */
/*   Updated: 2024/04/11 12:01:03 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	rlt;
	char	sign;

	rlt = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		rlt = rlt * 10 + *str - 48;
		str++;
	}
	return (rlt * sign);
}

static void	append(t_stack **stack, int nb)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = nb;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	stack_init(t_stack **a, char **argv)
{
	long	nb;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			free_errors(a);
		nb = ft_atol(argv[i]);
		if (nb > LONG_MAX || nb < LONG_MIN)
			free_errors(a);
		if (error_duplicate(*a, nb))
			free_errors(a);
		append(a, nb);
		i++;
	}
}
