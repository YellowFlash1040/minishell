/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:01:27 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/16 18:11:24 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLERS_H
# define SIGNAL_HANDLERS_H

# include <readline/readline.h>
# include <unistd.h>
# include <signal.h>

void	interactive_sigint_handler(int signum);
void	main_signals_handler(int signum);
void	forked_signals_handler(int signum);

#endif