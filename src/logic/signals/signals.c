/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akovtune <akovtune@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/06 16:59:01 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/14 14:17:42 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	initialize_sigactions(t_sigaction *sigint, t_sigaction *sigquit);
void	choose_handlers(t_sigmode mode, t_sigaction *sigint,
			t_sigaction *sigquit);
void	assign_handlers(t_sigaction *sigint, t_sigaction *sigquit);

void	set_handlers(t_sigmode mode)
{
	t_sigaction	sigint;
	t_sigaction	sigquit;

	initialize_sigactions(&sigint, &sigquit);
	choose_handlers(mode, &sigint, &sigquit);
	assign_handlers(&sigint, &sigquit);
}

void	initialize_sigactions(t_sigaction *sigint, t_sigaction *sigquit)
{
	sigset_t	sa_mask;
	int			sa_flags;

	ft_bzero(sigint, sizeof(t_sigaction));
	ft_bzero(sigquit, sizeof(t_sigaction));
	sigemptyset(&sa_mask);
	sigaddset(&sa_mask, SIGINT);
	sigaddset(&sa_mask, SIGQUIT);
	sa_flags = SA_RESTART;
	sigint->sa_mask = sa_mask;
	sigquit->sa_mask = sa_mask;
	sigint->sa_flags = sa_flags;
	sigquit->sa_flags = sa_flags;
}

void	choose_handlers(t_sigmode mode, t_sigaction *sigint,
	t_sigaction *sigquit)
{
	if (mode == InteractiveSignals)
	{
		sigint->sa_handler = interactive_sigint_handler;
		sigquit->sa_handler = SIG_IGN;
	}
	else
	{
		sigint->sa_handler = main_sigint_handler;
		sigquit->sa_handler = SIG_IGN;
	}
}

void	assign_handlers(t_sigaction *sigint, t_sigaction *sigquit)
{
	sigaction(SIGINT, sigint, NULL);
	sigaction(SIGQUIT, sigquit, NULL);
}

void	reset_signal_handlers_to_default(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
