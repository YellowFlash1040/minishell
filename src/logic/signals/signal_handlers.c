/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:00:40 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/16 18:11:24 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handlers.h"

extern int		g_received_signal;
// int		g_received_signal = -1;

void	interactive_sigint_handler(int signum)
{
	g_received_signal = signum;
	if (signum == SIGINT)
		write(STDOUT_FILENO, "\n", 1);
	else if (signum == SIGQUIT)
		write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	main_signals_handler(int signum)
{
	g_received_signal = signum;
	if (signum == SIGINT)
		write(STDOUT_FILENO, "\n", 1);
	else if (signum == SIGQUIT)
		write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
}

void	forked_signals_handler(int signum)
{
	g_received_signal = signum;
}
