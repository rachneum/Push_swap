/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:27:42 by rachou            #+#    #+#             */
/*   Updated: 2024/03/24 15:02:19 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack **a)
{
	size_t	count;
	t_stack	*first;

	count = 1;
	first = *a;
	if (!a || !*a)
		return (0);
	while ((*a)->next)
	{
		*a = (*a)->next;
		++count;
	}
	*a = first;
	return (count);
}

int nb_len(int nbr)//Permet d'avoir le nombre de chiffres de mon nb.
{
    int len;

    len = 0;
    if (nb < 0)
        nb *= -1;
    if (nb < 10)
        return (1);
    while (nb >= 10)
    {
        nb = nb / 10
        len++;
    }
    return (len);
}

int find_max(t_stack *a)
{
    int bits_max;

    bits_max = INT_MIN;
    if (!a)
        return (0);
    while (a)
    {
        if (bits_max < nb_len(a->value))
            bits_max = nb_len(a->value);//Permettre d'avoir la taille du nombre contenant le plus de chiffres.
        a = a->next;
    }
    return (bits_max);

}
