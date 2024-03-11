/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:40:30 by rachou            #+#    #+#             */
/*   Updated: 2024/03/09 14:52:33 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if (argc < 2 || argc == 2 & !argv[1][0])//Ou si dans le deuxième arg la position 0 est vide.
        return (0);
    if (argc == 2)//Si il y a deux arguments.
        argv = ft_split(argv[1], ' ');
    if (!argv)
        return (0);
    a = malloc(sizeof(t_stack));
    if (!a)
        return (0);
    b = malloc(sizeof(t_stack));
}
