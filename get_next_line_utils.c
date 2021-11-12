/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:11:58 by vsimeono          #+#    #+#             */
/*   Updated: 2021/11/12 16:14:18 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	str = (char *)s;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (*(str + i) == c)
			return (str + i);
		i++;
	}
	if (c == 0)
		return (str + len + 1);
	return (NULL);
}

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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < (int) n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	// free((void *)dst);
	// free((void *)src);
	return (dst);
}

char	*line_buf_join(char *s1, char *s2)
{
	int		lens1;
	int		lens2;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2 && (*s2 != '\n'))
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	if (*s2 == '\n')
		str[i] = *s2;
	return (str);
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

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (i < (int) n)
	{
		*(p + i) = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
	{
		return (NULL);
	}
	ft_bzero(p, count * size);
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	
	ft_memcpy(str, s1, lens1);
	ft_memcpy(str + lens1, s2, lens2);
	*(str + lens1 + lens2) = '\0';
	free((void *) s1);
	return (str);
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