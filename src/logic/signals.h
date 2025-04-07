/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/06 17:27:12 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/07 15:22:54 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

typedef enum sigmode
{
	Interactive,
	NonInteractive
}	t_sigmode;

void	set_handlers(t_sigmode mode);
#endif
