/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:44:23 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/26 14:59:19 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_builder.h"

int	build_std_files(t_command *command);

int	build_command(t_command **command)
{
	t_command	*command_v;
	int			result;

	if (!command)
		return (EMPTY_COMMAND_REF_ERR);
	*command = init_command();
	if (!*command)
		return (COMMAND_INIT_ERR);
	command_v = *command;
	result = build_std_files(command_v);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

int	build_std_files(t_command *command)
{
	command->input_file = init_file();
	if (!command->input_file)
		return (INPUT_FILE_INIT_ERR);
	command->input_file->fd = STDIN_FILENO;
	command->output_file = init_file();
	if (!command->output_file)
		return (OUTPUT_FILE_INIT_ERR);
	command->output_file->fd = STDOUT_FILENO;
	command->error_file = init_file();
	if (!command->error_file)
		return (ERROR_FILE_INIT_ERR);
	command->error_file->fd = STDERR_FILENO;
	return (SUCCESS);
}
