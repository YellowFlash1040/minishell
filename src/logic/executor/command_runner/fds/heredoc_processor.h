/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_processor.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:36:20 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/06 16:44:49 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_PROCESSOR_H
# define HEREDOC_PROCESSOR_H

# include <readline/readline.h>
# include <unistd.h>
# include "heredoc.h"
# include "global_status_codes.h"

int	process_heredoc(t_heredoc *heredoc);

#endif