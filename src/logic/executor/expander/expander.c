/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibenne <ibenne@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/26 12:38:15 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/04 17:07:12 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "ft_string.h"
#include "variable.h"
#include "environment.h"
#include "command.h"
#include "lst_to_str.h"
#include "token.h"
#include "tokenizer_utils.h"
#include "tokenizer.h"
#include "parser_utils.h"
#include "expanders.h"

int	expand_command(t_command *command)
{
	t_list_node	*int_node;

	if (expand_arguments(command) != SUCCESS)
		return (FAILURE);
	int_node = command->intermediate_files->head;
	while (int_node && int_node->value)
	{
		expand_path(command->environment, int_node->value);
		int_node = int_node->next;
	}
	if (command->input_file && command->input_file->fd != STDIN_FILENO)
		expand_path(command->environment, command->input_file);
	if (command->output_file && command->output_file->fd != STDOUT_FILENO)
		expand_path(command->environment, command->output_file);
	return (SUCCESS);
}

void	expand_commands(t_list **commands)
{
	t_list_node	*node;

	node = (*commands)->head;
	while (node)
	{
		expand_command((t_command *)node->value);
		node = node->next;
	}
}
