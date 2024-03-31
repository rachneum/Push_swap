/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:40:30 by rachou            #+#    #+#             */
/*   Updated: 2024/03/29 10:40:39 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc < 2 || (argc == 2 && !argv[1][0]))//Ou si dans le deuxième arg la position 0 est vide.
        return (0);
    if (argc == 2)//Si il y a deux arguments.
        argv = ft_split(argv[1], ' ');
    if (!argv)
        return (0);
}
