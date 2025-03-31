/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akovtune <akovtune@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/16 14:02:49 by akovtune      #+#    #+#                 */
/*   Updated: 2025/03/30 16:30:36 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"
#include "token.h"
#include "tokenizer.h"
#include "pipeline.h"
#include "parser.h"
#include "expander.h"

int	export(t_command *command)
{
	// t_list			*env;
	t_string_array	args;
	// t_list			*tokens;
	// t_variable		*variable;
	int				i;

	if (!command || !command->arguments || !command->environment)
		return (FAILURE);
	args = command->arguments;
	// env = command->environment;
	i = 1;
	while (args[i])
	{
		// tokens = create_token_list(&args[i]);
		// if (tokens)
		// {
		// 	if (parse_variable(tokens, &variable) != SUCCESS)
		// 	{
		// 		destroy_list(&tokens, free_token);
		// 		i++;
		// 		continue ;
		// 	}
		// 	expand_variable(env, variable);
		// 	set_env_variable(env, variable->name, variable->value, variable->is_exported);
		// 	destroy_list(&tokens, free_token);
		// }
		i++;
	}
	return (SUCCESS);
}
