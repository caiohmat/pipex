/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:33:37 by chideyuk          #+#    #+#             */
/*   Updated: 2021/12/07 23:16:37 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	counter;

	if (len == 0)
		return (0);
	counter = 0;
	while ((*s1 != '\0') && (*s2 != '\0')
		&& (counter < len - 1) && (*s1 == *s2))
	{
		s1++;
		s2++;
		counter++;
	}
	return (((unsigned char) *s1) - ((unsigned char) *s2));
}
