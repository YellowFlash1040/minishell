/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   heredoc_processor.c								:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: akovtune <akovtune@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/26 18:03:39 by akovtune		  #+#	#+#			 */
/*   Updated: 2025/04/16 16:57:59 by akovtune		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "heredoc_processor.h"

extern int		g_received_signal;

int		capture_heredoc(int pipefd[2], t_string delimiter);
void	heredoc_child(int write_fd, t_string delimiter);
void	collect_input(int write_fd, t_string delimiter);
int		handle_heredoc_child(pid_t pid);
int		close_unused_fds(void);

int	process_heredoc(t_heredoc *heredoc)
{
	int	result;
	int	pipe_fd[2];

	if (!heredoc->delimiter)
		return (FAILURE);
	result = pipe(pipe_fd);
	if (result == -1)
		return (perror("pipe"), result);
	result = capture_heredoc(pipe_fd, heredoc->delimiter);
	close(pipe_fd[WRITE_END]);
	if (result != SUCCESS)
		return (close(pipe_fd[READ_END]), result);
	heredoc->fd = pipe_fd[READ_END];
	return (SUCCESS);
}

int	capture_heredoc(int pipefd[2], t_string delimiter)
{
	pid_t	pid;
	int		exit_status;

	pid = fork();
	if (pid == -1)
		return (perror("fork"), FAILURE);
	if (pid == 0)
	{
		close(pipefd[READ_END]);
		heredoc_child(pipefd[WRITE_END], delimiter);
	}
	else
	{
		signal(SIGINT, main_signals_handler);
		signal(SIGQUIT, main_signals_handler);
		exit_status = handle_heredoc_child(pid);
		reset_signal_handlers_to_default();
		return (exit_status);
	}
	return (SUCCESS);
}

void	heredoc_child(int write_fd, t_string delimiter)
{
	t_string	delimiter_with_nl;
	t_sigaction	sa;

	sa.sa_handler = forked_signals_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	delimiter_with_nl = ft_strjoin(delimiter, "\n");
	if (!delimiter_with_nl)
		exit (FAILURE);
	collect_input(write_fd, delimiter_with_nl);
	free(delimiter_with_nl);
	close_unused_fds();
	close(write_fd);
	if (g_received_signal == -1)
		exit(SUCCESS);
	exit(g_received_signal);
}

void	collect_input(int write_fd, t_string delimiter)
{
	t_string	line;

	while (true)
	{
		if (g_received_signal != -1)
			break ;
		write(STDOUT_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			if (g_received_signal == -1)
				write(STDOUT_FILENO, "\n", 1);
			break ;
		}
		if (ft_strcmp(line, delimiter))
		{
			free(line);
			break ;
		}
		write(write_fd, line, strlen(line));
		free(line);
	}
}

int	handle_heredoc_child(pid_t pid)
{
	int	result;
	int	status;
	int	exit_status;

	result = waitpid(pid, &status, 0);
	if (result == -1)
		return (CHILD_HANDLER_ERR);
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	else if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		if (exit_status == SIGINT || exit_status == SIGQUIT)
			return (128 + exit_status);
		return (exit_status);
	}
	else
		return (FAILURE);
}
