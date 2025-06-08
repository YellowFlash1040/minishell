/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akovtune <akovtune@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/16 14:02:49 by akovtune      #+#    #+#                 */
/*   Updated: 2025/04/14 14:26:10 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

int	process_env_variable_manipulation_command(t_command *command,
		bool is_exported);

int	set(t_command *command)
{
	int	result;

	if (!command || !command->arguments || !command->environment)
		return (FAILURE);
	result = process_env_variable_manipulation_command(command, false);
	return (result);
}
