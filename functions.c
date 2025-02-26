/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:17:59 by esever            #+#    #+#             */
/*   Updated: 2025/02/26 20:17:35 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	if (!destsize)
		return (ft_strlen((char *)src));
	while (src[i] && (i < destsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (ft_strlen((char *)src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	end;
	size_t	s_len;
	char	*d;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start > (s_len))
		return (ft_strdup(""));
	end = start + len;
	if (end > (s_len))
		len = s_len - start;
	d = malloc((len + 1) * sizeof(char));
	if (!d)
		return (NULL);
	ft_strlcpy(d, s + start, len + 1);
	return ((char *)d);
}

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

size_t	check(char **list, size_t count)
{
	if (!list[count])
	{
		while (count > 0)
			free(list[--count]);
		free(list);
		return (0);
	}
	return (1);
}

void	free_split(char **list)
{
	size_t	i;

	if (!list)
		return;
	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	size_t	count = 0;
	const char	*begin;

	if (!s || !(list = malloc(sizeof(char *) * (count_word(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			begin = s;
			while (*s && *s != c)
				s++;
			if (!(list[count++] = ft_substr(begin, 0, s - begin)))
			{
				free_split(list);
				return (NULL);
			}	
		}
	}
	list[count] = NULL;
	return (list);
}

