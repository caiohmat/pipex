/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:18:07 by chideyuk          #+#    #+#             */
/*   Updated: 2021/12/07 23:19:10 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stddef.h>
# include <stdio.h>

int		ft_error(char *msg1, char *msg2, char *msg3, int ret);
void	*ft_nullerror(char *msg1, char *msg2, char *msg3);
char	*ft_pathfinder(char **args, char **env);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *b, size_t len);

#endif