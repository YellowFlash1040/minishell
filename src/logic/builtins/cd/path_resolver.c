/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_resolver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:01:51 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/18 15:25:04 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

t_string	get_home_directory(t_list *env);
t_string	replace_tilde_with_home(t_string path, t_list *env);

t_string	get_new_directory(t_list *env, t_string_array args)
{
	t_string	new_directory;

	if (args[1] == NULL || ft_strcmp(args[1], ""))
		return (get_home_directory(env));
	if (ft_strcmp(args[1], "-"))
	{
		new_directory = get_env_variable(env, "OLDPWD");
		if (!new_directory)
		{
			print_error_message("cd: OLDPWD not set\n");
			return (NULL);
		}
		printf("%s\n", new_directory);
		return (new_directory);
	}
	return (args[1]);
}
// else if (index_of('~', args[1]) != -1)
// 	return (replace_tilde_with_home(args[1], env));

t_string	get_home_directory(t_list *env)
{
	t_string	user_home_directory;

	user_home_directory = get_env_variable(env, "HOME");
	if (!user_home_directory)
	{
		user_home_directory = getenv("HOME");
		if (!user_home_directory)
			return (NULL);
	}
	return (user_home_directory);
}

t_string	replace_tilde_with_home(t_string path, t_list *env)
{
	t_string	user_home_folder;
	t_string	new_directory;
	t_string	temp;

	user_home_folder = get_home_directory(env);
	if (!user_home_folder)
		return (NULL);
	temp = ft_substr(path, index_of('~', path) + 1, ft_strlen(path));
	if (!temp)
		return (NULL);
	new_directory = ft_strjoin(user_home_folder, temp);
	free(temp);
	if (!new_directory)
		return (NULL);
	return (new_directory);
}
