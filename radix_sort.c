/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:07:37 by rachou            #+#    #+#             */
/*   Updated: 2024/03/14 16:00:15 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    radix_sort(t_stack *a, t_stack *b)
{

}

int radix_sort_index(t_stack *a)
{
    int max_element;
    
    max_element = find_max(a);
    if (!a)
        return (0);
    while (a)
    {
        
    }
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
    int max_element;

    max_element = INT_MIN;
    if (!a)
        return (0);
    while (a)
    {
        if (max_element < nb_len(a->value))
            max_element = nb_len(a->value);//Permettre d'avoir la taille du nombre contenant le plus de chiffres.
        a = a->next;
    }
    return (max_element);

}
