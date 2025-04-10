/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:27:12 by ismo              #+#    #+#             */
/*   Updated: 2025/04/09 14:07:05 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "signal_handlers.h"
# include <signal.h>

typedef enum sigmode
{
	ForkSignals,
	MainSignals,
	InteractiveSignals,
}	t_sigmode;

void	set_handlers(t_sigmode mode);
#endif
