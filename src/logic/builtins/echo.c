/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:57:24 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/08 14:09:57 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

int	echo(t_string_array args)
{
	int i;

	i = -1;
	while (args[++i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
	}
	printf("\n");
	destroy_string_array(&args);

	return (SUCCESS);
}
