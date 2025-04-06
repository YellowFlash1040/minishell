/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/06 16:59:01 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/06 19:09:18 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include <signal.h>
#include <readline/readline.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern int		g_received_signal;

void	interactive_sigint_handler(int signum)
{
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_received_signal = signum;
}

void	non_interactive_sigint_handler(int signum)
{
	rl_on_new_line();
	g_received_signal = signum;
}
void	set_handlers(t_sigmode mode)
{
	struct sigaction act_sigint;
	struct sigaction act_sigquit;

	memset(&act_sigint, 0, sizeof(act_sigint));
	memset(&act_sigquit, 0, sizeof(act_sigquit));

	if (mode == Interactive)
	{
		act_sigint.sa_handler = &interactive_sigint_handler;
		sigaction(SIGINT, &act_sigint, NULL);
		act_sigquit.sa_handler = SIG_IGN;
		sigaction(SIGQUIT, &act_sigquit, NULL);
	}
	else if (mode == NonInteractive)
	{
		act_sigint.sa_handler = &non_interactive_sigint_handler;
		sigaction(SIGINT, &act_sigint, NULL);
	}
}


