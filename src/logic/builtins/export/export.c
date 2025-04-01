/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akovtune <akovtune@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/16 14:02:49 by akovtune      #+#    #+#                 */
/*   Updated: 2025/04/01 13:59:06 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipeline.h"
#include "export.h"
#include "token.h"
#include "tokenizer.h"
#include "parser.h"

int	export(t_command *command)
{
	t_list			*env;
	t_list			*tokens;
	char			*name;
	char			*value;
	t_string_array	args;
	int				i;

	if (!command || !command->arguments || !command->environment)
		return (FAILURE);
	args = command->arguments;
	env = command->environment;
	i = 1;
	while (args[i])
	{
		tokens = create_token_list(args[i], 1);
		if (parse_variable(tokens, &name, &value) != SUCCESS)
			return (destroy_list(&tokens, free_token), FAILURE);
		if (set_env_variable(env, name, value, 1) != SUCCESS)
			return (destroy_list(&tokens, free_token), free(name), free(value), FAILURE);
		destroy_list(&tokens, free_token);
		i++;
	}
	return (SUCCESS);
}
