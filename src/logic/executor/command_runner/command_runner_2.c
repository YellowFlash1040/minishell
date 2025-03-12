/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_runner_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:21:03 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/12 14:31:53 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_runner.h"

int	print_not_found_err(t_string binary_path)
{
	t_string	message;
	int			result;

	message = ft_strjoin(binary_path, ": command not found\n");
	if (!message)
		return (perror("Error"), MALLOC_FAIL_ERR);
	result = print_error_message(message);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

int	run_builtin(t_command *command)
{
	const t_string	names[] = {"echo", "cd",
		"pwd", "export", "unset", "env", "exit", NULL};
	const t_builtin	builtins[] = {echo};
	int				i;

	i = -1;
	while (names[++i])
		if (ft_strcmp(command->executable, names[i]))
			return (builtins[i](command->arguments));
	return (FAILURE);
}

// ◦ echo with option -n
// ◦ cd with only a relative or absolute path
// ◦ pwd with no options
// ◦ export with no options
// ◦ unset with no options
// ◦ env with no options or arguments
// ◦ exit with no options