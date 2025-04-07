/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   term_col.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/04 15:24:30 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/07 15:20:22 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <stdbool.h>

bool	needs_newline(void)
{
	char				c;
	struct termios		term;
	bool				needs_nl;

	needs_nl = false;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
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
	while (c && c != 'R' && read(STDIN_FILENO, &c, 1) >= 1)
		continue ;
	term.c_lflag |= (ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	return (needs_nl);
}
