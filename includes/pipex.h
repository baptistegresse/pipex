#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "../libft/libft.h"

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

char	**ft_split_slash(char const *s, char c);

#endif