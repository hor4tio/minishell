/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:53:22 by alganoun          #+#    #+#             */
/*   Updated: 2021/02/22 16:22:15 by alganoun         ###   ########lyon.fr   */
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
