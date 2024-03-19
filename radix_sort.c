/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:07:37 by rachou            #+#    #+#             */
/*   Updated: 2024/03/19 09:35:13 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	ft_check_index(t_stack **a, int len)//Vérifie l'index d'un élément dans une pile, ce qui est utile dans le contexte du tri pour déterminer la position correcte d'un élément.
{
	t_stack	*first;//Pointeur vers le premier élément de la pile.
	int		i;//Compteur pour parcourir les éléments de la pile.
	int		nb;//Valeur de l'élément actuel de la pile.
	int		index;//Index actuel de l'élément dans la pile.

	first = *a;
	i = 0;
	index = 1;
	nb = (*a)->value;
	while (i <= len)
	{
		nb = (*a)->value;//Met à jour nb avec la valeur de l'élément actuel.
		*a = (*a)->next;//Passer à l'élément suivant.
		i++;
	}
	*a = first;
	while (*a)
	{
		if ((*a)->value < nb)
		index++;
		*a = (*a)->next;
	}
	*a = first;
	return (index);
}

static void	ft_put_index(t_stack **a, int pos, int index)
{
	t_stack	*first;
	int		i;

	first = *a;
	i = 0;
	while (i < pos)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->index = index;
	*a = first;
}

void	ft_fill_index(t_stack *a)
{
	int		i;
	int		index_value;

	i = 0;
	while (i < stack_len(a))
	{
		index_value = ft_check_index(a, i);
		ft_put_index(a, i, index_value);
		i++;
	}
}

int	ft_check_sort(t_stack **a)
{
	t_stack	*first;//Pointeur vers le premier élément de la pile.
	int		tmp;//La valeur de l'élément actuel de la pile.

	first = *a;//first est initialisé avec le premier élément de la pile.
	tmp = (*a)->value;//tmp est initialisé avec la valeur de l'élément actuel (le premier élément de la pile).
	while (*a)//Tant que je parcours ma stack a.
	{
		if ((*a)->value < tmp)//Compare la valeur de l'élément actuel avec la valeur stockée dans tmp.
		{
			*a = first;
			return (0);//Retourne 0 car la pile n'est pas triée.
		}
		tmp = (*a)->value;//Met à jour tmp avec la valeur de l'élément actuel.
		*a = (*a)->next;//Passe à l'élément suivant.
	}
	*a = first;//Après avoir parcouru toute la pile, on réinitialise la pile à sa position initiale en la pointant vers first.
	return (1);//Retourne 1 pour indiquer que la pile est triée.
}

