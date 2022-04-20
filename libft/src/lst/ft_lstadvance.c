/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadvance.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 17:02:34 by mforstho      #+#    #+#                 */
/*   Updated: 2022/04/07 12:22:53 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadvance(t_list **lst, void (*del)(void *))
{
	t_list *tmp = (*lst)->next;
	ft_lstdelone(*lst, del);
	*lst = tmp;
}
