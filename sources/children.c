/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:08:37 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/10 16:27:49 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void ft_parsing_args(t_pipe *data, char *args)
{
	data->cmd_args = ft_split(args, ' ');
	data->cmd = data->cmd_args[0];
}

static void ft_path_finder(t_pipe *data)
{
	size_t	index;
	char	*tempory_path;

	index = -1;
	while (data->cmd_paths[++index])
	{
		tempory_path = ft_strjoin(data->cmd_paths[index], data->cmd);
		if (!access(tempory_path, F_OK))
		{
			data->paths = tempory_path;
			free(tempory_path);
			break ;
		}
		data->paths = NULL;
		free(tempory_path);
	}
}


void ft_first_child(t_pipe *data, char *argv[], char *envp[])
{
	if (dup2(data->tube[1], STDOUT_FILENO) == -1)
		return (ft_free_all(data, 1));
	if (dup2(data->infile, STDIN_FILENO) == -1)
		return (ft_free_all(data, 1));
	close(data->tube[0]);
	close(data->infile);
	ft_parsing_args(data, argv[2]);
	ft_path_finder(data);
	execve(data->paths, data->cmd_args, envp);
}

void ft_second_child(t_pipe *data, char *argv[], char *envp[])
{
	if (dup2(data->tube[0], STDIN_FILENO) == -1)
		return (perror("error dup"), ft_free_all(data, 1));
	if (dup2(data->outfile, STDOUT_FILENO) == -1)
		return (perror("error dup"), ft_free_all(data, 1));
	close(data->tube[1]);
	close(data->outfile);
	ft_parsing_args(data, argv[3]);
	ft_path_finder(data);
	execve(data->paths, data->cmd_args, envp);
}