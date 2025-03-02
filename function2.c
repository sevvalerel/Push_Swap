/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:26:20 by seerel            #+#    #+#             */
/*   Updated: 2025/03/02 12:52:19 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_word(const char *p, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (p[i])
	{
		while (p[i] == c && p[i])
			i++;
		if (p[i] != c && p[i])
		{
			len++;
			while (p[i] != c && p[i])
				i++;
		}
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	end;
	size_t	s_len;
	char	*d;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start > s_len)
		return (ft_strdup(""));
	end = start + len;
	if (end > s_len)
		len = s_len - start;
	d = malloc((len + 1) * sizeof(char));
	if (!d)
		return (NULL);
	ft_strlcpy(d, s + start, len + 1);
	return ((char *)d);
}

static char	*get_next_word(const char **s, char c)
{
	const char	*begin;

	while (**s == c)
		(*s)++;
	if (!**s)
		return (NULL);
	begin = *s;
	while (**s && **s != c)
		(*s)++;
	return (ft_substr(begin, 0, *s - begin));
}

char	**ft_split(char const *s, char c)
{
	char		**list;
	size_t		count;
	char		*word;

	count = 0;
	if (!s)
		return (NULL);
	list = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!list)
		return (NULL);
	while (*s)
	{
		word = get_next_word(&s, c);
		if (word)
		{
			list[count++] = word;
			if (!word)
			{
				free_split(list);
				return (NULL);
			}
		}
	}
	list[count] = NULL;
	return (list);
}
