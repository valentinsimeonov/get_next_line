/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:09:11 by vsimeono          #+#    #+#             */
/*   Updated: 2021/11/13 18:39:51 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len-- > 0)
		{
			*(d + len) = *(s + len);
		}
	}
	else
	{
		while (len-- > 0)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	return (d);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	free((void *)(s1));
	while (j < ft_strlen(s2))
	{
		ptr[i] = s2[j];
		j++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	lenstr;

	i = 0;
	if (!s)
		return (NULL);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	lenstr = ft_strlen(s);
	if (start >= lenstr)
		return (p);
	while (i < len)
	{
		*(p + i) = *(s + start);
		i++;
		start++;
	}
	*(p + i) = '\0';
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (i < (int)n)
	{
		*(p + i) = '\0';
		i++;
	}
}
