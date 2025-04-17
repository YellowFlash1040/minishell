/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:04:44 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 14:05:18 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

typedef struct gnl
{
	char	*buffer;
	char	*temp;
	int		nl_index;
	ssize_t	rb_c;
}	t_gnl;

char	*read_buffer_size(int fd, ssize_t *rb_c);
char	*extractn(char *s, size_t n);
char	*join(char *s1, char *s2);
size_t	len(char *str);

#endif