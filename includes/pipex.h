/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:15:31 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/10 16:15:22 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pipe
{
	pid_t	pid1;
	pid_t	pid2;

	int		tube[2];

	int		infile;
	int		outfile;

	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}               t_pipe;

void	ft_free_paths(t_pipe *data, int boolean);
void	ft_free_args(t_pipe *data, int boolean);
void	ft_free_all(t_pipe *data, int boolean);

void 	ft_first_child(t_pipe *data, char *argv[], char *envp[]);
void	ft_second_child(t_pipe *data, char *argv[], char *envp[]);

void	ft_pipex(t_pipe *data, char *argv[], char *envp[]);

#endif
