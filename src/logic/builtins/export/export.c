/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:02:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/11 14:37:19 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

int	process_env_variable_manipulation_command(t_command *command,
		bool is_exported);

int	export(t_command *command)
{
	int	result;

	result = process_env_variable_manipulation_command(command, true);
	return (result);
}
