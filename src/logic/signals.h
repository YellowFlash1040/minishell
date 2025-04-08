/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/06 17:27:12 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/08 01:07:57 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

typedef enum sigmode
{
	MainSignals,
	HeredocSignals,
}	t_sigmode;

void	set_handlers(t_sigmode mode);
#endif
