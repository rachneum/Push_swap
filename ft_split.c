/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:45:13 by rachou            #+#    #+#             */
/*   Updated: 2024/04/05 15:45:49 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_free(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static char	*ft_put(char *wds, char const *s, int i, int len_wds)
{
	int	j;

	j = 0;
	while (len_wds > 0)
	{
		wds[j] = s[i - len_wds];
		j++;
		len_wds--;
	}
	wds[j] = '\0';
	return (wds);
}

static int	ft_cnt_wds(char const *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			cnt++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (cnt);
}

static char	**ft_split_wds(char const *s, char c, char **dst, int num_wds)
{
	int	i;
	int	wds;
	int	len_wds;

	i = 0;
	wds = 0;
	len_wds = 0;
	while (wds < num_wds)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			len_wds++;
		}
		dst[wds] = (char *)malloc(sizeof(char) * (len_wds + 1));
		if (!dst[wds])
			return (ft_free(dst, wds));
		ft_put(dst[wds], s, i, len_wds);
		len_wds = 0;
		wds++;
	}
	dst[wds] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char			**dst;
	unsigned int	num_wds;

	if (!s)
		return (NULL);
	num_wds = ft_cnt_wds(s, c);
	dst = (char **)malloc(sizeof(char *) * (num_wds + 1));
	if (!dst)
		return (NULL);
	dst = ft_split_wds(s, c, dst, num_wds);
	return (dst);
}
