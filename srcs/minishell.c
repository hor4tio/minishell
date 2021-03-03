/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoufi <musoufi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 08:37:43 by alganoun          #+#    #+#             */
/*   Updated: 2021/03/03 13:44:18 by musoufi          ###   ########lyon.fr   */
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

int		input_process(char *line, t_cmd **cmd)
{
	int		i;
	//char	*word;
	int		cmd_nb;

	i = 0;
	cmd_nb = word_count(line);
	if (((*cmd)->cmdline = cmd_parser(line, cmd_nb)) == NULL)
		return (write_errors(3, NULL));
	if (execute_command(cmd) == -1)
		return (-1);
	free_tab(&((*cmd)->cmdline), cmd_nb + 1);
	return(0);
}

int		main(/*int argc, char **argv, char **data*/)
{
	int ret;
	//int	fd;
	char *line;
	t_cmd	*cmd;

	ret = 1;
	if(init_struct(&cmd) == -1)
		return (write_errors(3, NULL));
	/*if (display_txt("banner.txt") == -1)
		return (-1);*/
	while(ret != 0)
	{
		write(1, "[minishell-1.0$ ", 16);
		get_next_input(&line);
		if ((ret = ft_strncmp(line, "exit", 4)) == 0)
			write(1, EXIT_MSG, ft_strlen(EXIT_MSG));
		else if (input_process(line, &cmd) == -1)
			return(-1);
		safe_free(&line);
	}
	safe_free(&line);
	safe_free((char **)&cmd);
	return (0);
}


// il faut que je vois pour gerer le " tout seul
