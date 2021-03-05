/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:00:40 by alganoun          #+#    #+#             */
/*   Updated: 2021/03/05 14:34:12 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int		word_count(char *str)
// {
// 	int i;
// 	int nb;
// 	int	found;

// 	i = 0;
// 	nb = 0;
// 	found = 0;
// 	while (str[i])
// 	{
// 		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
// 			found = 0;
// 		else if (found == 0)
// 		{
// 			nb++;
// 			found = 1;
// 		}
// 		i++;
// 	}
// 	return (nb);
//}

void	cmd_parser(t_cmd **cmd)
{
	int			i;
	t_prcess 	*current;

	i = 0;
	current = NULL;
	while ((*cmd)->cmdline[i] != NULL)
	{
		if ((*cmd)->prcess == NULL)
		{
			(*cmd)->prcess = ft_prcessnew((char *)(*cmd)->cmdline[i]);
			current = (*cmd)->prcess;
		}
		else
		{
			current->next = ft_prcessnew((char *)(*cmd)->cmdline[i]);
			current = current->next;
		}
		i++;
	}
	current->next = NULL;
}

//int		cmd_analyzer(char **tab, t_cmd **cmd)
//{
//
//}
