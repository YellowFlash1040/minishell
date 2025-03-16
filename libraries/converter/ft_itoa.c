/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:33:21 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/16 15:24:49 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_number_of_digits(long int n);
static void	fill_the_rest_of_the_digits(char **res, int res_length, long int n);

char	*ft_itoa(int n)
{
	int		res_length;
	char	*res;

	res_length = count_number_of_digits(n);
	if (n < 0)
		res_length++;
	res = (char *)malloc(sizeof(char) * (res_length + 1));
	if (!res)
		return (NULL);
	res[res_length] = '\0';
	if (n < 0)
		res[0] = '-';
	if (n != 0)
		fill_the_rest_of_the_digits(&res, res_length, n);
	else
		res[0] = '0';
	return (res);
}

static void	fill_the_rest_of_the_digits(char **res, int res_length, long int n)
{
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		(*res)[res_length - 1] = n % 10 + '0';
		n /= 10;
		res_length--;
	}
}

static int	count_number_of_digits(long int n)
{
	int	count;

	if (n < 0)
		n = -n;
	count = 1;
	while (n / 10 > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
