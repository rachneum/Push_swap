/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:55:18 by rachou            #+#    #+#             */
/*   Updated: 2024/04/18 10:42:14 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = 0;
	b = 0;
	if (argc < 2)
		return (0);
	if (((argc == 2) && !argv[1][0]))
		return (write(1, "Error\n", 6));
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!argv)
		return (write(1, "Error\n", 6));
	stack_init(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	return (0);
}
