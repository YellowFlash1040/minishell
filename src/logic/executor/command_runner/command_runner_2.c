/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_runner_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:21:03 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/10 14:21:16 by akovtune         ###   ########.fr       */
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
