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

int	build_command(t_command **command_ref)
{
	t_command	*command;
	int			result;

	if (!command_ref)
		return (EMPTY_COMMAND_REF_ERR);
	*command_ref = init_command();
	if (!*command_ref)
		return (COMMAND_INIT_ERR);
	command = *command_ref;
	result = build_std_files(command);
	if (result != SUCCESS)
		return (result);
	command->intermediate_files = init_list();
	if (!command->intermediate_files)
		return (LIST_INIT_ERR);
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
