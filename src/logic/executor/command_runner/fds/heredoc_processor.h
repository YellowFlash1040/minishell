/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_processor.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:36:20 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/16 16:38:23 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_PROCESSOR_H
# define HEREDOC_PROCESSOR_H

# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include "heredoc.h"
# include "global_status_codes.h"
# include "get_next_line.h"
# include "signal_handlers.h"

# define FORK_FUNC_ERR 193
# define CHILD_HANDLER_ERR 191

# include "pipeline_runner.h"

int	process_heredoc(t_heredoc *heredoc);

#endif