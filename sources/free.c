/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:04:24 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/10 16:24:50 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_paths(t_pipe *data, int boolean)
{
	ft_putstr_fd("path\n", 2);
	ft_putnbr_fd(boolean, 2);
	size_t	index;

	index = 0;
	while (data->cmd_paths[index])
		free(data->cmd_paths[index++]);
	free(data->cmd_paths);
	if (boolean)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	ft_free_args(t_pipe *data, int boolean)
{
	ft_putstr_fd("args\n", 2);
	ft_putnbr_fd(boolean, 2);


	size_t	index;

	index = 0;
	while (data->cmd_args[index])
		free(data->cmd_args[index++]);
	free(data->cmd_args);
	if (boolean)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	ft_free_all(t_pipe *data, int boolean)
{
	ft_putstr_fd("all\n", 2);
	ft_putnbr_fd(boolean, 2);


	ft_free_paths(data, boolean);
	ft_free_args(data, boolean);
	if (boolean)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
