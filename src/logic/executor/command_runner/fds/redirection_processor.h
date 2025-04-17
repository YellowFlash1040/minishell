/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirection_processor.h                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akovtune <akovtune@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/06 16:39:06 by akovtune      #+#    #+#                 */
/*   Updated: 2025/04/17 14:10:34 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_PROCESSOR_H
# define REDIRECTION_PROCESSOR_H

# include "heredoc_processor.h"
# include "file_processor.h"

int	process_redirections(t_list *redirections, int pipe_fd[2]);

#endif
