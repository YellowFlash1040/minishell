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

int	main(int argc, char *argv[], char *envp[])
{
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
// ARG=hello; OK="how are you?"; FILE=input.txt; echo $OK; cat $FILE;
// ; ls | grep $OK > $FILE
// export OK="how are you?"
// unset
