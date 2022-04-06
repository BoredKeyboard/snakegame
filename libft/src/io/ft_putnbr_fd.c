/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 14:25:33 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 13:56:49 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Writes an integer

#include "libft.h"
#include <unistd.h>

// Calculates the amount of digits n contains
static int	count_digits(int n)
{
	int		count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

// Calculates the amount of tens for the amount of digits
static int	calc_tens(int count)
{
	int	i;
	int	tens;

	i = 1;
	tens = 1;
	while (i < count)
	{
		tens *= 10;
		i++;
	}
	return (tens);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		count;
	int		i;
	char	wn;
	int		tens;

	if (n < 0)
		write(fd, "-", 1);
	if (n == -2147483648)
	{
		write(fd, "2", 1);
		n = -147483648;
	}
	if (n < 0)
		n *= -1;
	count = count_digits(n);
	tens = calc_tens(count);
	i = 0;
	while (i < count)
	{
		wn = ((n / tens) % 10) + '0';
		write(fd, &wn, 1);
		tens /= 10;
		i++;
	}
}

/*
2564 / 1000 = 2
2 % 10 = 2
2564 / 100 = 25
25 % 10 = 5
2564 / 10 = 256
256 % 10 = 6
2564 / 1 = 2564
2564 % 10 = 4
 */
