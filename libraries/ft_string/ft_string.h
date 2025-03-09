/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:35:18 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/09 13:55:48 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdbool.h>
# include <stdlib.h>

typedef char*	t_string;

int		ft_strlen(char *str);
int		index_of(char c, char *str);
int		last_index_of(char c, char *str);
bool	ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *str);
void	replace(char *str, char old, char new);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		count_words(char *s, char delimiter);
char	*extract_word(char *s, int *i, char c);
char	**ft_split(char *s, char c);

#endif