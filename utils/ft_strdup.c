/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:33:37 by chideyuk          #+#    #+#             */
/*   Updated: 2021/12/07 23:16:23 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*pdst;
	char	*psrc;
	size_t	counter;

	if (dst == NULL && src == NULL)
		return (dst);
	pdst = dst;
	psrc = (char *)src;
	counter = 0;
	while (counter < len)
	{
		pdst[counter] = psrc [counter];
		counter++;
	}
	return (dst);
}

char	*ft_strdup(const char *str)
{
	char	*copy;
	size_t	lenght;

	lenght = ft_strlen(str) + 1;
	copy = malloc (lenght);
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, str, lenght);
	return (copy);
}
