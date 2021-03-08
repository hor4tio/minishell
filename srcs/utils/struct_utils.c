/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allanganoun <allanganoun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:53:22 by alganoun          #+#    #+#             */
/*   Updated: 2021/03/08 15:46:21 by allanganoun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		init_struct(t_cmd **cmd)
{
	if (!(*cmd = (t_cmd *)malloc(1 * sizeof(t_cmd))))
		return (-1);
	(*cmd)->prcess = NULL;
	(*cmd)->cmdline = NULL;
	return (0);
}

t_prcess		*ft_prcesslast(t_prcess *prcess)
{
	if (prcess == NULL)
		return (NULL);
	while (prcess->next != NULL)
		prcess = prcess->next;
	return (prcess);
}

void	ft_prcessadd_back(t_prcess **aprcess, t_prcess *new)
{
	t_prcess *last;

	if (*aprcess == NULL)
	{
		new->next = NULL;
		*aprcess = new;
	}
	else
	{
		last = ft_prcesslast(*aprcess);
		last->next = new;
		new->next = NULL;
	}
}

t_prcess	*ft_prcessnew(char *content)
{
	t_prcess *list;

	if (!(list = malloc(sizeof(t_prcess))))
		return (NULL);
	list->data = content;
	list->id = 0;
	return (list);
}