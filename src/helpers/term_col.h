/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_col.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:26:56 by ismo              #+#    #+#             */
/*   Updated: 2025/04/10 15:12:11 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_COL_H
# define TERM_COL_H

bool	needs_newline(void);
void	set_term_attr(void);
void	unset_term_attr(void);
void	print_optional_newline(void);
#endif
