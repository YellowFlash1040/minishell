/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:59:01 by ismo              #+#    #+#             */
/*   Updated: 2025/04/10 15:13:47 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	choose_handlers(t_sigmode mode, struct sigaction *sigint,
			struct sigaction *sigquit);
void	initialize_sigactions(t_sigmode mode, struct sigaction *sigint,
			struct sigaction *sigquit);

void	set_handlers(t_sigmode mode)
{
	struct sigaction	act_sigint;
	struct sigaction	act_sigquit;

	ft_memset(&act_sigint, 0, sizeof(struct sigaction));
	ft_memset(&act_sigquit, 0, sizeof(struct sigaction));
	initialize_sigactions(mode, &act_sigint, &act_sigquit);
	choose_handlers(mode, &act_sigint, &act_sigquit);
	sigaction(SIGINT, &act_sigint, NULL);
	sigaction(SIGQUIT, &act_sigquit, NULL);
}

void	initialize_sigactions(t_sigmode mode, struct sigaction *sigint,
	struct sigaction *sigquit)
{
	sigset_t	sa_mask;

	sigemptyset(&sa_mask);
	sigaddset(&sa_mask, SIGINT);
	sigaddset(&sa_mask, SIGQUIT);
	sigint->sa_mask = sa_mask;
	sigquit->sa_mask = sa_mask;
	if (mode == MainSignals)
	{
		sigint->sa_flags = SA_RESTART;
		sigquit->sa_flags = SA_RESTART;
	}
}

void	choose_handlers(t_sigmode mode, struct sigaction *sigint,
	struct sigaction *sigquit)
{
	if (mode == InteractiveSignals)
	{
		sigint->sa_handler = &interactive_sigint_handler;
		sigquit->sa_handler = SIG_IGN;
	}
	else if (mode == MainSignals)
	{
		sigint->sa_handler = &main_sigint_handler;
		sigquit->sa_handler = SIG_IGN;
	}
	else if (mode == ForkSignals)
	{
		sigint->sa_handler = &fork_sigint_handler;
		sigquit->sa_handler = SIG_DFL;
	}
}
