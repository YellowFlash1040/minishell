/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/02/11 16:03:52 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/26 14:59:34 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "global_status_codes.h"
#include "list.h"
#include "token.h"
#include "tokenizer.h"
#include "pipeline.h"
#include "pipeline_builder.h"
#include "pipeline_runner.h"
#include "parser_utils.h"
#include "parser.h"
#include "environment.h"
#include "expander.h"
#include "term_col.h"
#include "signals.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/ioctl.h>
#include <termios.h>

int		g_received_signal = -1;

void	run_shell_loop(t_list *env);
int		process_line(t_string line, t_list *env);

int	main(int argc, char *argv[], char *envp[])
{
	t_list		*env;

	(void) argc;
	(void) argv;
	env = init_environment(envp);
	set_handlers(MainSignals);
	if (!env)
		return (FAILURE);
	run_shell_loop(env);
	destroy_environment(&env);
	return (0);
}

void	run_shell_loop(t_list *env)
{
	char		*line;
	int			result;

	set_handlers(InteractiveSignals);
	line = readline("$> ");
	set_handlers(MainSignals);
	while (line)
	{
		if (*line)
		{
			result = process_line(line, env);
			free(line);
			if (result != SUCCESS)
				break ;
			print_optional_newline();
		}
		set_handlers(InteractiveSignals);
		line = readline("$> ");
		set_handlers(MainSignals);
	}
}

int	process_line(t_string line, t_list *env)
{
	t_list		*tokens;
	t_pipeline	*pipeline;

	pipeline = NULL;
	tokens = create_token_list(line, 0);
	if (!tokens
		|| (parse_pipeline(tokens, &pipeline, env) != SUCCESS
			&& tokens->count > 1))
		print_error_message("Syntax error\n");
	else if (read_token(tokens, 0)->type == EndOfInput)
		return (destroy_list(&tokens, free_token), SUCCESS);
	else if (pipeline)
	{
		expand_commands(&pipeline->commands);
		g_received_signal = -1;
		run_a_pipeline(pipeline);
		destroy_pipeline(&pipeline);
	}
	add_history(line);
	if (tokens)
		destroy_list(&tokens, free_token);
	return (SUCCESS);
}
