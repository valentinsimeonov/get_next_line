/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:48:46 by vsimeono          #+#    #+#             */
/*   Updated: 2021/11/12 16:03:31 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buf		[BUFFER_SIZE + 1];
	int					read_count;
	char				*line;

	line = (char *)ft_calloc(1, sizeof(char *));
	while (!ft_strchr(buf, '\n'))
	{
		if (*buf)
			line = ft_strjoin(line, buf);
		read_count = read(fd, buf, BUFFER_SIZE);
		if (read_count <= 0 && !(*line))
		{
			free(line);
			return (NULL);
		}
		buf[read_count] = '\0';
		if (!ft_strchr(buf, '\n') && read_count < BUFFER_SIZE)
		{
			line = ft_strjoin(line, buf);
			ft_bzero(buf, 1);
			return (line);
		}
	}
	line = move_in_line(line, buf, read_count);
	return (line);
}

char	*move_in_line(char *line, char *buf, int read_count)
{
	char	*pointer;
	int		first_line_len;
	int		second_line_len;
	char	*temp;

	pointer = ft_strchr(buf, '\n');
	first_line_len = read_count - ft_strlen(pointer + 1);
	second_line_len = read_count - first_line_len;
	temp = ft_substr(buf, 0, first_line_len);
	line = ft_strjoin(line, temp);
	buf = ft_memmove(buf, &buf[first_line_len], second_line_len);
	ft_bzero(&buf[second_line_len], first_line_len);
	if (temp)
		free(temp);
	return (line);
}

int		main()
{
	int		fd;
	char	*str;
	fd = open("myfile.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str != 0)
	{
		// printf("%p\n", str);
		printf("%s", str);
		str = get_next_line(fd);
		
	}
	close(fd);
	return (0);
}