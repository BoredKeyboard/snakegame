/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 14:15:51 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 13:57:49 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Writes a string

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}
