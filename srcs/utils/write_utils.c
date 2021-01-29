/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:00:24 by alganoun          #+#    #+#             */
/*   Updated: 2021/01/29 15:14:00 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


ssize_t		write_output(char *str)
{
	return ((write(1, str, ft_strlen(str))) + (write(1, "\n", 1)));
}

int		write_errors(int option, char *str)
{
	write(1, "Bash: ", 7);
	if (option == 1)
	{
		write(1, str, ft_strlen(str));
		write(1, " not found\n", 11);
	}
	else if (option == 2)
	{
		write(1, str, ft_strlen(str));
		write(1, ": command not found\n", 20);
		return (0);
	}
	return (-1);
}
