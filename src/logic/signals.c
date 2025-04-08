/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:59:01 by ismo              #+#    #+#             */
/*   Updated: 2025/04/08 18:22:30 by ibenne           ###   ########.fr       */
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
// int		g_received_signal = -1;

void	interactive_sigint_handler(int signum)
{
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_received_signal = signum;
}

void	main_sigint_handler(int signum)
{
	g_received_signal = signum;
}

void	fork_sigint_handlers(int signum)
{
	write(STDOUT_FILENO, "\n", 1);
	g_received_signal = signum;
	exit(1);
}

void	set_handlers(t_sigmode mode)
{
	struct sigaction	act_sigint;
	struct sigaction	act_sigquit;
	sigset_t			sa_mask;

	sigemptyset(&sa_mask);
	sigaddset(&sa_mask, SIGINT);
	sigaddset(&sa_mask, SIGQUIT);
	act_sigint.sa_mask = sa_mask;
	act_sigquit.sa_mask = sa_mask;
	act_sigint.sa_flags = SA_RESTART;
	act_sigquit.sa_flags = SA_RESTART;
	if (mode == InteractiveSignals)
	{
		act_sigint.sa_handler = &interactive_sigint_handler;
		sigaction(SIGINT, &act_sigint, NULL);
		act_sigquit.sa_handler = SIG_IGN;
		sigaction(SIGQUIT, &act_sigquit, NULL);
	}
	else if (mode == MainSignals)
	{
		act_sigint.sa_handler = &main_sigint_handler;
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
