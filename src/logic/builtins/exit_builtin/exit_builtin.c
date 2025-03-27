/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:08:18 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/20 14:31:03 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_builtin.h"

bool	check_and_atoi(t_string str, int *res);

int	exit_builtin(t_command *command)
{
	int	exit_status;

	if (get_str_arr_length(command->arguments) > 2)
	{
		command->exit_status_code = FAILURE;
		print_error_message("exit: too many arguments\n");
		return (SUCCESS);
	}
	exit_status = SUCCESS;
	if (command->arguments[1])
	{
		if (!check_and_atoi(command->arguments[1], &exit_status))
			exit(2);
	}
	exit(exit_status);
}

bool	check_and_atoi(t_string str, int *res)
{
	bool	m;
	int		digit;

	if (!str || !*str)
		return (false);
	*res = 0;
	m = false;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			m = true;
	while (*str >= '0' && *str <= '9')
	{
		*res *= 10;
		digit = *str++ - '0';
		*res += digit;
	}
	if (*str != '\0')
		return (false);
	if (m)
		*res = -*res;
	return (true);
}
