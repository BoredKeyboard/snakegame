/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_u_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 15:28:26 by mforstho      #+#    #+#                 */
/*   Updated: 2022/02/02 15:49:08 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_u_fd(unsigned int n, int fd)
{
	int				count;
	int				i;
	char			wn;
	unsigned int	tens;

	count = count_digits_u_base(n, 10);
	tens = calc_power_u_base(count, 10);
	i = 0;
	while (i < count)
	{
		wn = ((n / tens) % 10) + '0';
		write(fd, &wn, 1);
		tens /= 10;
		i++;
	}
}
