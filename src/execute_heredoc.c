/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:34:22 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/06 01:56:07 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc_no_problem(t_token *token, int *pipe_fd)
{
	while (token != NULL && token->next != NULL && token->type != PIPE_TYPE)
	{
		if (token->next->type == REDIRECT_TYPE
			&& ft_strncmp(token->next->value, "<<", 2) == 0)
		{
			if (ft_strncmp(token->value, "cat", 4) == 0
				|| ft_strncmp(token->value, "head", 5) == 0
				|| ft_strncmp(token->value, "tail", 5) == 0
				|| ft_strncmp(token->value, "sort", 5) == 0)
			{
				if (*pipe_fd != 0)
					close(*pipe_fd);
				*pipe_fd = 0;
				return (1);
			}
			return (0);
		}
		token = token->next;
	}
	return (1);
}

static void	readable_for_heredoc(char *file_name, t_token *token)
{
	int	fd;

	t_token *prev_token = NULL;

	// grep i << ,
	while (token != NULL && token->next != NULL && ft_strncmp(token->next->value, "<<", 2))
	{
		prev_token = token;

		token = token->next;
	}


	if (prev_token != NULL && ft_strncmp(prev_token->value, "grep", 5) == 0) // token->next->value << ise şartı lazım olur mu?
	{

		fd = open(file_name, O_RDONLY, 0644);
		if (fd == -1)
		{
			ft_printf(STDERR_FILENO, "File can't opened !\n");
			return ;
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
		return ;
	}


	if (ft_strncmp(token->value, "cat", 4) == 0
		|| ft_strncmp(token->value, "head", 5) == 0
		|| ft_strncmp(token->value, "tail", 5) == 0
		|| ft_strncmp(token->value, "sort", 5) == 0)
	{
		fd = open(file_name, O_RDONLY, 0644);
		if (fd == -1)
		{
			ft_printf(STDERR_FILENO, "File can't opened !\n");
			return ;
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

static void	heredoc_handler(char *delimiter, int fd)
{
	char	*line;
	char	**temp_token;

	while (1)
	{
		temp_token = (char **)malloc(sizeof(char *) * 2);
		ft_printf(STDIN_FILENO, "> ");
		line = get_next_line(0);

		printf("line : %s\n", line);

		temp_token[0] = ft_strdup(line);
		temp_token[1] = NULL;

		printf("line : %s\n", line);

		if (line == NULL)
		{
			clear_temp_token(temp_token, line);
			break ;
		}
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1) == 0)
		{
			clear_temp_token(temp_token, line);
			break ;
		}
		change_all_env_variable_to_value(temp_token);
		ft_printf(fd, "%s\n", temp_token[0]);
		clear_temp_token(temp_token, line);
	}
	close(fd);
}

void	execute_heredoc(char *file_name, t_token *token, int *heredoc_count)
{
	int	fd;

	*heredoc_count += 1;
	fd = open(".heredoc_temp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	int test = open("test_x",O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_printf(test, "Geliyon mu gelmiyon mu amk\n");
	if (fd == -1)
	{
		ft_printf(STDERR_FILENO, "File can't opened !\n");
		g_shell->exit_status = 1;
		g_shell->file_error_found = 1;
		return ;
	}

	printf("fd : %d\n", fd);

	heredoc_handler(file_name, fd);

	ft_printf(test, "%d", *heredoc_count);

	//if (g_shell->heredoc_count == *heredoc_count)
		readable_for_heredoc(".heredoc_temp", token);
}
