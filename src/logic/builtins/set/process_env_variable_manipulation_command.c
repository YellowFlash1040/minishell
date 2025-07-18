/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process_env_variable_manipulation_command.c        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akovtune <akovtune@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/11 14:07:24 by akovtune      #+#    #+#                 */
/*   Updated: 2025/04/14 14:25:21 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

int	process_env_variable_manipulation_command(t_command *command,
	bool is_exported)
{
	t_list			*env;
	t_list			*tokens;
	char			*name;
	char			*value;
	int				i;

	env = command->environment;
	i = 0;
	while (command->arguments[++i])
	{
		tokens = create_token_list(command->arguments[i], true);
		if (!tokens)
			return (print_error_message("export: syntax error\n"), FAILURE);
		if (parse_variable(tokens, &name, &value) != SUCCESS)
		{
			print_error_message("export: parsing error\n");
			return (destroy_list(&tokens, free_token), FAILURE);
		}
		if (set_env_variable(env, name, value, is_exported) != SUCCESS)
			return (destroy_list(&tokens, free_token),
				free(name), free(value), FAILURE);
		free(name);
		destroy_list(&tokens, free_token);
	}
	return (SUCCESS);
}
