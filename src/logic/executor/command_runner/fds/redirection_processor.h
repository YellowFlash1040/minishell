/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_processor.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:39:06 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/06 16:50:04 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_PROCESSOR_H
# define REDIRECTION_PROCESSOR_H

# include "heredoc_processor.h"
# include "file_processor.h"

int	process_redirections(t_list *redirections);

#endif