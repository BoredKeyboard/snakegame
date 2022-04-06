/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_u_base_fd.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 15:26:35 by mforstho      #+#    #+#                 */
/*   Updated: 2022/02/02 15:49:00 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_u_base_fd(unsigned int n, int fd, char *base_chars)
{
	int				count;
	int				i;
	char			wn;
	unsigned int	power;
	int				base;

	base = ft_strlen(base_chars);
	count = count_digits_u_base(n, base);
	power = calc_power_u_base(count, base);
	i = 0;
	while (i < count)
	{
		wn = base_chars[(n / power) % base];
		write(fd, &wn, 1);
		power /= base;
		i++;
	}
}
