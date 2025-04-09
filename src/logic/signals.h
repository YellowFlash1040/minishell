/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:27:12 by ismo              #+#    #+#             */
/*   Updated: 2025/04/08 14:43:43 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

typedef enum sigmode
{
	ForkSignals,
	MainSignals,
	InteractiveSignals,
}	t_sigmode;

void	set_handlers(t_sigmode mode);
#endif
