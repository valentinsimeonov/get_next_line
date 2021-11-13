/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:07:24 by vsimeono          #+#    #+#             */
/*   Updated: 2021/11/13 18:38:54 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)ft_calloc(1, sizeof(char));
	line = because_of_norminette(fd, line);
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*because_of_norminette(int fd, char *line)
{
	static char buf[MAX_FD][BUFFER_SIZE + 1];
	int			read_count;

	while (!ft_strchr(buf[fd], '\n'))
	{
		if (*buf[fd])
			line = ft_strjoin(line, buf[fd]);
		read_count = read(fd, buf[fd], BUFFER_SIZE);
		if (read_count <= 0 && !(*line))
		{
			free(line);
			return (NULL);
		}
		buf[fd][read_count] = '\0';
		if (!ft_strchr(buf[fd], '\n') && read_count < BUFFER_SIZE)
		{
			line = ft_strjoin(line, buf[fd]);
			ft_bzero(buf[fd], 1);
			return (line);
		}
	}
	line = move_in_line(line, buf[fd]);
	return (line);
}

char	*move_in_line(char *line, char *buf)
{
	char	*pointer;
	int		first_line_len;
	int		second_line_len;
	char	*temp;
	int		len_buf;

	len_buf = ft_strlen(buf);
	pointer = ft_strchr(buf, '\n');
	first_line_len = len_buf - ft_strlen(pointer + 1);
	second_line_len = len_buf - first_line_len;
	temp = ft_substr(buf, 0, first_line_len);
	line = ft_strjoin(line, temp);
	buf = ft_memmove(buf, &buf[first_line_len], second_line_len);
	ft_bzero(&buf[second_line_len], first_line_len);
	free(temp);
	return (line);
}

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
