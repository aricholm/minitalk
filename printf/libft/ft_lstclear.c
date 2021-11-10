/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:06:36 by aricholm          #+#    #+#             */
/*   Updated: 2021/11/02 18:23:33 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*rem;

	tmp = *lst;
	while (tmp)
	{
		(del)(tmp->content);
		rem = tmp;
		tmp = tmp->next;
		free (rem);
	}
	*lst = 0;
}
