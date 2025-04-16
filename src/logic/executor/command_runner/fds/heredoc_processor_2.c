/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   heredoc_processor_2.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: akovtune <akovtune@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/16 17:33:35 by akovtune		  #+#	#+#			 */
/*   Updated: 2025/04/16 17:33:48 by akovtune		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <dirent.h>
#include <unistd.h>
#include "heredoc_processor.h"

void	fallback_function(void);

int	close_unused_fds(void)
{
	int				fd;
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir("/proc/self/fd");
	if (dir)
	{
		entry = readdir(dir);
		while (entry)
		{
			if (entry->d_type == DT_LNK)
			{
				fd = ft_atoi(entry->d_name);
				if (fd > 2)
					close(fd);
			}
			entry = readdir(dir);
		}
		closedir(dir);
	}
	else
		fallback_function();
	return (SUCCESS);
}

void	fallback_function(void)
{
	int	fd;

	fd = 2;
	while (++fd <= 255)
		close(fd);
}
