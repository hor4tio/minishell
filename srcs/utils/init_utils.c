/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:53:22 by alganoun          #+#    #+#             */
/*   Updated: 2021/02/11 09:07:18 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"



int		init_struct(t_cmd **cmd)
{
	if (!((*cmd) = (t_cmd *)malloc(sizeof(t_cmd))))
		return (-1);
	(*cmd)->cmdline = NULL;
	return (0);
}
