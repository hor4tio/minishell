/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:06:00 by alganoun          #+#    #+#             */
/*   Updated: 2021/02/22 09:49:24 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	safe_free(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

char	**free_tab(char **tab, int count)
{
	int i;

	i = 0;
	while (count != 0)
	{
		safe_free(&tab[i]);
		i++;
		count--;
	}
	return (NULL);
}
