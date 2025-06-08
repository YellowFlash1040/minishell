/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_result_to_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:46:54 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/23 15:27:56 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipeline_runner.h"

int	save_result_to_env(t_list *env, int pipeline_status_code)
{
	int			result;
	t_string	string_status_code;

	string_status_code = ft_itoa(pipeline_status_code);
	if (!string_status_code)
		return (FAILURE);
	result = set_env_variable(env, "?", string_status_code, false);
	if (result != SUCCESS)
		return (free(string_status_code), result);
	return (SUCCESS);
}
