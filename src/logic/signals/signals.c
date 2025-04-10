/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:59:01 by ismo              #+#    #+#             */
/*   Updated: 2025/04/09 14:08:07 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	choose_handlers(t_sigmode mode, struct sigaction *sigint,
			struct sigaction *sigquit);
void	initialize_sigactions(struct sigaction *sigint,
			struct sigaction *sigquit);

void	set_handlers(t_sigmode mode)
{
	struct sigaction	act_sigint;
	struct sigaction	act_sigquit;

	initialize_sigactions(&act_sigint, &act_sigquit);
	choose_handlers(mode, &act_sigint, &act_sigquit);
	sigaction(SIGINT, &act_sigint, NULL);
	sigaction(SIGQUIT, &act_sigquit, NULL);
}

void	initialize_sigactions(struct sigaction *sigint,
	struct sigaction *sigquit)
{
	sigset_t	sa_mask;

	sigemptyset(&sa_mask);
	sigaddset(&sa_mask, SIGINT);
	sigaddset(&sa_mask, SIGQUIT);
	sigint->sa_mask = sa_mask;
	sigquit->sa_mask = sa_mask;
	sigint->sa_flags = SA_RESTART;
	sigquit->sa_flags = SA_RESTART;
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
