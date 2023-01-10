/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:12:14 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/10 16:28:46 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_pipex(t_pipe *data, char *argv[], char *envp[])
{
	if (pipe(data->tube) == -1)
		return (perror("salut"), ft_free_paths(data, 1));
	data->pid1 = fork();
	if (data->pid1 < 0)
		return (perror("salut"), ft_free_paths(data, 1));
	if (data->pid1 == 0)
		ft_first_child(data, argv, envp);
	data->pid2 = fork();
	if (data->pid2 < 0)
		return (perror("salut"), ft_free_all(data, 1));
	if (data->pid2 == 0)
		ft_second_child(data, argv, envp);
	exit(1);
	close(data->tube[0]);
	close(data->tube[1]);
	waitpid(data->pid1, NULL, 0);
	waitpid(data->pid2, NULL, 0);
}
