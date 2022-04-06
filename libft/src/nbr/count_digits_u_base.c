/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_digits_u_base.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 15:22:22 by mforstho      #+#    #+#                 */
/*   Updated: 2022/02/02 15:22:35 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits_u_base(unsigned int n, int base)
{
	int		count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}
