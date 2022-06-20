/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:19:27 by chideyuk          #+#    #+#             */
/*   Updated: 2021/12/10 18:59:50 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_run(char *str, char **env)
{
	char	**args;
	char	*path;
	int		counter;
	int		error;

	args = ft_split(str, ' ');
	path = ft_pathfinder(args, env);
	counter = 0;
	if (!path)
	{
		error = ft_error("pipex: ", args[0], ": command not found\n", 127);
		while (args[counter])
			free(args[counter++]);
		free(args);
		exit(error);
	}
	execve(path, args, env);
	free(path);
	error = ft_error("pipex: ", args[0], ": command not found\n", 127);
	while (args[counter])
		free(args[counter++]);
	free(args);
	exit(error);
}

void	ft_prepandrun(char *str, char **env)
{
	int	pid;
	int	fd[2];

	pipe(fd);
	pid = fork();
	if (pid != 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(-1, NULL, WNOHANG);
	}
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		ft_run(str, env);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	int	rfile;
	int	wfile;

	if (argc != 5)
		return (ft_error("invalid number of arguments", "", "", 1));
	rfile = open(argv[1], O_RDONLY);
	wfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (rfile < 0)
	{
		close(rfile);
		close(wfile);
		return (ft_error("pipex: ", argv[1],
				": No such file or directory\n", 1));
	}
	dup2(rfile, 0);
	dup2(wfile, 1);
	ft_prepandrun(argv[2], env);
	ft_run(argv[3], env);
	return (0);
}	
