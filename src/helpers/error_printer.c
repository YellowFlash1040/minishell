/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:23:10 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/14 14:24:53 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_printer.h"

int	print_error_message(t_string message)
{
	int	result;

	result = write(STDERR_FILENO, message, ft_strlen(message));
	if (result == -1)
		return (perror("Error"), FAILURE);
	return (SUCCESS);
}
