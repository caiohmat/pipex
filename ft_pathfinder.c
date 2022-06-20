/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:21:28 by chideyuk          #+#    #+#             */
/*   Updated: 2021/12/07 23:22:08 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_con(char *path, char *arg)
{
	char	*newpath;
	char	*temp;

	newpath = ft_strjoin(path, "/");
	temp = newpath;
	newpath = ft_strjoin(temp, arg);
	free(temp);
	if (open(newpath, O_RDONLY) > 0)
		return (newpath);
	free(newpath);
	return (NULL);
}

char	*ft_pathfinder(char **args, char **env)
{
	int		counter;
	char	*path;
	char	**split;

	counter = 0;
	while ((env[counter]) && (ft_strncmp(env[counter], "PATH=", 5)))
		counter++;
	if (!env[counter])
		return (NULL);
	path = ft_strdup(ft_strchr(env[counter], '=') + 1);
	split = ft_split(path, ':');
	counter = 0;
	free(path);
	path = NULL;
	while (split[counter] && !path)
		path = ft_con(split[counter++], args[0]);
	counter = 0;
	while (split[counter])
		free(split[counter++]);
	free(split);
	return (path);
}
