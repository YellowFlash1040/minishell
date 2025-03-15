/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:25:09 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/14 18:44:23 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_runner.h"

int	setup_command_io(t_command *command);
int	launch_binary(t_string name, t_string_array args);
int	setup_binary_path(t_string *name_ref);
int	print_not_found_err(t_string binary_path);

int	execute_external(t_command *command)
{
	int	result;

	result = setup_command_io(command);
	if (result != SUCCESS)
		return (result);
	return (launch_binary(command->executable, command->arguments));
}

int	launch_binary(t_string name, t_string_array args)
{
	int	result;

	setup_binary_path(&name);
	result = execve(name, args, NULL);
	if (result == -1)
	{
		if (errno == ENOENT)
		{
			result = print_not_found_err(name);
			if (result != SUCCESS)
				return (result);
			return (FAILURE);
			// return (SUCCESS); 
			//if I return SUCCESS here than I have 
			//dup2 error, since my child process continues doing the same stuff
			//as the parent when it actually has to stop.
			//but now I have another possible problem which is:
			//if print_not_found_err() call fails
			//I will continue pipeline execution
			//when I think actually I need to stop the whole minishell, since
			//it means that either something is wrong with malloc() or write()
			//but then it means that I have to return different status codes 
			//from here
			//and check what was the error inside the pipeline. and if it is not:
			//NOT_FOUND_ERR, then I have to quit. if not - just continue with the pipeline() execution
			//
			//after some more thinking and a test in bash with command:
			//ls | ./a.out | cat main.c
			//where the pipeline exit status is 0, and there is no error in the bash
			//I decided that I will leave it as it is, since it seems to be fine, since
			//the child process will cleanup itself in either case
			//and if the parent will fail because of the same reason, namely malloc() or write() call
			//then the parent will also safely cleanup and exit
			//and if it was only execve() call fail, then again - it has nothing to do with the parent workflow
			//so I don't think I have anything to worry about here
		}
		return (perror("Error"), BINARY_LAUNCH_ERR);
	}
	return (SUCCESS);
}

int	setup_binary_path(t_string *name_ref)
{
	t_string	name;
	t_string	binary_path;
	int			result;

	name = *name_ref;
	result = find_binary(name, &binary_path);
	if (result != SUCCESS)
		return (result);
	if (binary_path != NULL)
	{
		free(name);
		*name_ref = binary_path;
	}
	return (SUCCESS);
}

int	print_not_found_err(t_string binary_path)
{
	t_string	message;
	int			result;

	message = ft_strjoin(binary_path, ": command not found\n");
	if (!message)
		return (perror("Error"), MALLOC_FAIL_ERR);
	result = print_error_message(message);
	free(message);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}
