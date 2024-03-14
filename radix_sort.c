/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:07:37 by rachou            #+#    #+#             */
/*   Updated: 2024/03/14 15:08:24 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    radix_sort(t_stack *a, t_stack *b)
{

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

int nb_into_index(t_stack *a)
{
    int nb_len;

    nb_len = INT_MIN;
    if (!a)
        return (0);
    while (a)
    {
        if (nb_len < nb_len(a->value))
            nb_len = nb_len(a->value);//Permettre d'avoir mon nb_MAX (nombre contenant le plus de chiffres, qui mer servira dans mon Radix).
        a = a->next;
    }
    return (nb_len);
}
