/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:45:13 by rachou            #+#    #+#             */
/*   Updated: 2024/04/12 13:10:52 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cnt_words(char *str, char sep)
{
	int		cnt;
	bool	inside_word;

	cnt = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == sep && *str)
			str++;
		while (*str != sep && *str)
		{
			if (!inside_word)
			{
				inside_word = true;
				cnt++;
			}
			str++;
		}
	}
	return (cnt);
}

static char	*get_next_words(char *str, char sep)
{
	static int	sp = 0;
	int			len;
	int			i;
	char		*next_str;

	len = 0;
	i = 0;
	while (str[sp] == sep)
		sp++;
	while ((str[len + sp] != sep) && str[len + sp])
		len++;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (!next_str)
		return (NULL);
	while ((str[sp] != sep) && str[sp])
		next_str[i++] = str[sp++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char sep)
{
	int		words_nbr;
	int		i;
	char	**s;

	i = 0;
	words_nbr = cnt_words(str, sep);
	s = malloc(sizeof(char *) * (words_nbr + 2));
	if (!s)
		return (NULL);
	while (words_nbr-- >= 0)
	{
		if (i == 0)
		{
			s[i] = malloc(sizeof(char));
			if (!s[i])
				return (NULL);
			s[i++][0] = '\0';
			continue ;
		}
		s[i++] = get_next_words(str, sep);
	}
	s[i] = NULL;
	return (s);
}
