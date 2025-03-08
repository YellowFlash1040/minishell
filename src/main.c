/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/02/11 16:03:52 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/26 14:59:34 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "error_printer.h"
// #include "parser.h"

// int	main(int argsc, char **args)
// {
// 	int			result;
// 	t_prompt	*prompt;

// 	if (argsc < 1)
// 		return (FAILURE);
// 	result = parse(args[1], &prompt);
// 	if (result != SUCCESS)
// 		return (result);
// 	destroy_prompt(&prompt);
// 	return (SUCCESS);
// }

// #include "pipeline_builder.h"
// #include "pipeline_runner.h"
#include <stdio.h>
#include "echo.h"


int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;

	// int i;

	// i=-1;
	// while (envp[++i])
	// 	printf("%s\n", envp[i]);

	t_string_array args;

	args = init_string_array(2);
	if (!args)
		printf("Malloc failed\n");
	args[0] = ft_strdup("hello");
	args[1] = ft_strdup("world");

	echo(args);

	return (0);
}

// Example 1
// ARG=hello; OK=hello;  echo ARG; ls | cat name.txt
//&&git log;

// Example 2
// ls | grep ok<input.txt<input2.txt> output2.txt> output.txt | wc - l;

// Example 3
// ARG = ok;
// echo	hello;
// echo ARG
// ls  >output.txt
// echo $?

// Example 4
// ARG=hello; OK="how are you?"; FILE=input.txt; echo $OK; cat $FILE; ls | grep $OK > $FILE
// export OK="how are you?"
// unset
