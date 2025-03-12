/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:57:24 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/12 14:25:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

bool	check_for_n_flag(t_string first_arg);

int	echo(t_string_array args)
{
	bool	n_flag_active;
	int		i;

	if (!args || !args[1])
		return (FAILURE);
	n_flag_active = check_for_n_flag(args[1]);
	if (!n_flag_active)
		i = 1;
	else
		i = 2;
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (!n_flag_active)
		printf("\n");
	return (SUCCESS);
}

bool	check_for_n_flag(t_string first_arg)
{
	int	i;

	if (!first_arg || first_arg[0] != '-')
		return (false);
	i = 1;
	while (first_arg[i])
	{
		if (first_arg[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

//I need to know whether the first argument is the -n flag, and if it is, 
//then I don't need to print it (the first argument)
//and I don't need to print the new line in the end