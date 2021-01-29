/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:51:41 by alganoun          #+#    #+#             */
/*   Updated: 2021/01/29 15:11:42 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		pwd_process()
{
	char *buffer;

	buffer = (char *)malloc(PATH_MAX);
	if (getcwd(buffer, PATH_MAX) != NULL)
		write_output(buffer);
	free(buffer);
	return (0);
}
