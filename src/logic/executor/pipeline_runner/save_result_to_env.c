/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_result_to_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:46:54 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/22 18:49:49 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipeline_runner.h"

int	set_result_to_env(t_list *env, int pipeline_status_code)
{
	int			result;
	t_string	variable_name;

	variable_name = ft_strdup("?");
	if (!variable_name)
		return (FAILURE);
	result = set_env_variable(env, variable_name, ft_itoa(pipeline_status_code), false);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}
