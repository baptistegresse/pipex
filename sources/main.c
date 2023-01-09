/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:05:52 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/09 17:37:19 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void ft_parsing_paths(t_pipe *data, char *envp[])
{
	size_t	index;

	index = 0;
	while (!ft_strnstr(envp[index], "PATH=", 5))
		index++;
	data->cmd_paths = ft_split(envp[index] + 5, ':');
	index = -1;
	while (data->cmd_paths[++index])
		data->cmd_paths[index] = ft_strjoin(data->cmd_paths[index], "/");
}

static void ft_parsing_args(t_pipe *data, char *args)
{
	data->cmd_args = ft_split(args, ' ');
	data->cmd = data->cmd_args[0];
}

static void ft_path_finder(t_pipe *data, char *envp[])
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

int main(int argc, char *argv[], char *envp[])
{
	t_pipe data;

	ft_parsing_paths(&data, envp);
	ft_parsing_args(&data, "ls -e");
	ft_path_finder(&data, envp);
	return (0);
}