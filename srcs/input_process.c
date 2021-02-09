/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:34:59 by alganoun          #+#    #+#             */
/*   Updated: 2021/02/09 08:22:19 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


int		input_parsing(char *line)
{
	int i;
	char *command;

	i = 0;
	command = NULL;
	while (line[i])
	{
		command = get_next_word(&(line[i]));
		if (input_process(command) == -1)
			return (-1);
		i = ft_strlen(command) - 1;
	}
	return (0);
}

int		input_process(char *command)
{
	if (ft_strcmp(command, "echo") == 0)
		return(echo_process());
	else if (ft_strcmp(command, "cd") == 0)
		return(cd_process());
	if (ft_strcmp(command, "pwd") == 0)
		return (pwd_process());
	else if (ft_strcmp(command, "export") == 0)
		return (export_process());
	else if (ft_strcmp(command, "unset") == 0)
		return (unset_process());
	else if (ft_strcmp(command, "env") == 0)
		return (env_process());
	else if (ft_strcmp(command, "bash -help", 10) == 0)
	{
		if (display_txt("version.txt") == -1 ||
			display_txt("minishell_help.txt"))
			return (-1);
	}
	else if (ft_strlen(command) > 0)
		return (write_errors(2, command));
	return(0);
}
