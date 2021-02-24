/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:36:40 by alganoun          #+#    #+#             */
/*   Updated: 2021/02/24 09:59:34 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		bash_process(t_cmd **cmd, char **tab)
{
	if (ft_strcmp(tab[1], "-help") == 0)
	{
		if (display_txt("version.txt") == -1)
			return (-1);
	}
	else if (tab[1] && tab[1][0] != '|' && tab[1][0] != '&')
		return (write_errors(WRONG_CMD, tab[1]));
	return (0);
}
