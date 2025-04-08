/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:59:01 by ismo              #+#    #+#             */
/*   Updated: 2025/04/08 14:44:32 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "ft_string.h"
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

void	fork_sigint_handlers(int signum)
{
	write(STDOUT_FILENO, "^C\n", 3);
	g_received_signal = signum;
	exit(1);
}

void	set_handlers(t_sigmode mode)
{
	struct sigaction	act_sigint;
	struct sigaction	act_sigquit;

	ft_memset(&act_sigint, 0, sizeof(act_sigint));
	ft_memset(&act_sigquit, 0, sizeof(act_sigquit));
	if (mode == InteractiveSignals)
	{
		act_sigint.sa_handler = &interactive_sigint_handler;
		sigaction(SIGINT, &act_sigint, NULL);
		act_sigquit.sa_handler = SIG_IGN;
		sigaction(SIGQUIT, &act_sigquit, NULL);
	}
	else if (mode == MainSignals)
	{
		act_sigint.sa_handler = SIG_IGN;
		sigaction(SIGINT, &act_sigint, NULL);
		act_sigquit.sa_handler = SIG_IGN;
		sigaction(SIGQUIT, &act_sigquit, NULL);
	}
	else if (mode == ForkSignals)
	{
		act_sigint.sa_handler = fork_sigint_handlers;
		sigaction(SIGINT, &act_sigint, NULL);
		act_sigquit.sa_handler = SIG_DFL;
		sigaction(SIGQUIT, &act_sigquit, NULL);
	}
}
