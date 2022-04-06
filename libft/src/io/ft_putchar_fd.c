/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 14:11:59 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 13:48:05 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Writes a character

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
