/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 08:37:43 by alganoun          #+#    #+#             */
/*   Updated: 2021/01/29 14:54:55 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		display_txt(char *str)
{
	int fd;
	int ret;
	char *line;
	ret = 1;

	fd = open(str, O_RDONLY);
	while(ret > 0)
	{
		ret = get_next_line(fd, &line);
		write_output(line);
		free(line);
	}
	ret = get_next_line(fd, &line);
	write_output(line);
	free(line);
	if (ret != 0)
		return (write_errors(1, str));
	return (0);
}

int		input_process(char *line)
{
	char *word;

	word = get_next_word(&line);
	//if (strncmp(line, "echo", 4) == 0)
	//	return(echo_process());
	//else if (strncmp(line, "cd", 2) == 0)
	//	return(cd_process());
	if (strncmp(line, "pwd", 3) == 0)
		return (pwd_process());
	//else if (strncmp(line, "export", 6) == 0)
	//	return (export_process());
	//else if (strncmp(line, "unset", 5) == 0)
	//	return (unset_process());
	//else if (strncmp(line, "env", 3) == 0)
	//	return (env_process());
	else if (strncmp(line, "bash -help", 10) == 0)
	{
		if (display_txt("version.txt") == -1 ||
			display_txt("minishell_help.txt"))
			return (-1);
	}
	else if (strlen(line) > 0)
		return (write_errors(2, word));
	return(0);
}

int		main()
{
	int ret;
	int	fd;
	char *line;

	ret = 1;
	if (display_txt("banner.txt") == -1)
		return (-1);
	while(ret != 0)
	{
		write(1, "[neo_bash-1.0$ ", 15);
		get_next_input(&line);
		if ((ret = ft_strncmp(line, "exit", 4)) == 0)
			write(1, EXIT_MSG, ft_strlen(EXIT_MSG));
		else if (input_process(line) == -1)
			return(-1);

	}
	return (0);
}
