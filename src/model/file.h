/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:52:21 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/21 14:34:00 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include "global_status_codes.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define FILE_INIT_ERR 140
# define FILE_OPEN_ERR 141
# define FD_DUP_ERR 142
# define EMPTY_FILE_MODE_ERR 143

typedef enum e_write_mode
{
	NONE = -1,
	/// @brief `>` Truncate mode
	TRUNCATE = O_WRONLY | O_CREAT | O_TRUNC,
	/// @brief `>>` Append mode
	APPEND = O_WRONLY | O_CREAT | O_APPEND,
	/// @brief `<` Reading mode
	READ = O_RDONLY | O_CREAT
}					t_write_mode;

typedef struct file
{
	/// @brief Default: `-1`
	int				fd;
	/// @brief Default: `NULL`
	char			*path;
	/// @brief Default: `NONE`. Possible values: `TRUNCATE`, `APPEND`, `READ`.
	t_write_mode	mode;
}					t_file;

typedef struct redirection
{
	int				standard_fd;
	t_file			*file;
}					t_redirection;

t_file				*init_file(void);
void				destroy_file(t_file **file);
int					redirect(int old_fd, int new_fd);
int					open_file(t_file *file);

#endif

/*
stdout (1) can be redirected:

With > (truncate mode, O_WRONLY | O_CREAT | O_TRUNC).
With >> (append mode, O_WRONLY | O_CREAT | O_APPEND).

*/

/*
stderr (2) is similar to stdout when redirected:

2> (truncate mode)
2>> (append mode)
*/
