/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:24:30 by ismo              #+#    #+#             */
/*   Updated: 2025/04/10 16:15:50 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <stdbool.h>
#include <sys/ioctl.h>

extern int	g_received_signal;

void	set_term_attr(void)
{
	struct termios		term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	unset_term_attr(void)
{
	struct termios		term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= (ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

bool	needs_newline(void)
{
	char				c;
	bool				needs_nl;

	needs_nl = false;
	write(STDOUT_FILENO, "\033[6n", 4);
	if (read(STDIN_FILENO, &c, 1) < 1)
		needs_nl = true;
	while (c && c != ';')
	{
		if (read(STDIN_FILENO, &c, 1) < 1)
			needs_nl = true;
	}
	if (read(STDIN_FILENO, &c, 1) < 1 || c != '1')
		needs_nl = true;
	if (read(STDIN_FILENO, &c, 1) < 1 || c != 'R')
		needs_nl = true;
	return (needs_nl);
}

void	print_optional_newline(void)
{
	set_term_attr();
	if (needs_newline())
	{
		printf("\x1b[1;30;47m%%\x1b[0m\n");
	}
	unset_term_attr();
	ioctl(STDIN_FILENO, TCFLSH, 0);
}
