/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibenne <ibenne@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/16 14:02:49 by akovtune      #+#    #+#                 */
/*   Updated: 2025/04/05 13:44:31 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

int	export(t_command *command)
{
	t_list			*env;
	t_list			*tokens;
	char			*name;
	char			*value;
	int				i;

	name = NULL;
	value = NULL;
	if (!command || !command->arguments || !command->environment)
		return (FAILURE);
	env = command->environment;
	i = 1;
	while (command->arguments[i])
	{
		tokens = create_token_list(command->arguments[i], true);
		if (parse_variable(tokens, &name, &value) != SUCCESS)
			return (destroy_list(&tokens, free_token), FAILURE);
		if (set_env_variable(env, name, value, true) != SUCCESS)
			return (destroy_list(&tokens, free_token),
				free(name), free(value), FAILURE);
		free(name);
		destroy_list(&tokens, free_token);
		i++;
	}
	return (SUCCESS);
}
