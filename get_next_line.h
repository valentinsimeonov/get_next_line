/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:58:05 by vsimeono          #+#    #+#             */
/*   Updated: 2021/11/12 11:47:13 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <stdlib.h>
# include <unistd.h>
 
# include <stdio.h>

# include <fcntl.h> // for open
# include <unistd.h> // for close

char	*get_next_line(int fd);

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*move_in_line(char *line, char *buf, int read_count);
char	*ft_strjoin(char const *s1, char const *s2);




#endif
