/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:27:12 by ismo              #+#    #+#             */
/*   Updated: 2025/04/11 17:15:32 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <signal.h>
# include "ft_memory.h"
# include "signal_handlers.h"

typedef struct sigaction	t_sigaction;

typedef enum sigmode
{
	MainSignals,
	InteractiveSignals
}	t_sigmode;

void	set_handlers(t_sigmode mode);
void	reset_signal_handlers_to_default(void);
#endif
