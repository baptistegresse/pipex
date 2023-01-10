/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:05:52 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/10 16:22:12 by bgresse          ###   ########.fr       */
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

int main(int argc, char *argv[], char *envp[])
{
	t_pipe data;

	if (argc != 5)
		return (ft_putstr_fd("Incorrect number of arguments.\n", 2),
		EXIT_FAILURE);
	data.infile = open(argv[1], O_RDONLY);
	data.outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (data.infile == -1 || data.outfile == -1)
		return (perror("open file"), EXIT_FAILURE);
	ft_parsing_paths(&data, envp);
	ft_pipex(&data, argv, envp);
	ft_free_all(&data, 0);
	return (EXIT_SUCCESS);
}
