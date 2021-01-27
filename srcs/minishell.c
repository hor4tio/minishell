/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 08:37:43 by alganoun          #+#    #+#             */
/*   Updated: 2021/01/27 14:39:37 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	banner_txt(const char *str)
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
		return (write_errors(BANNER));
	return (0);
}

//int		input_process(char *line)
//{
//
//}

int		main()
{
	int ret;
	int	fd;
	char *line;

	ret = 1;
	if (banner_txt("banner.txt") == -1)
		return (-1);
	while(ret != 0)
	{
		write(1, "[neo_bash-1.0$ ", 15);
		get_next_input(&line);

		if ((ret = ft_strcmp(line, "exit")) == 0)
			write (1, EXIT_MSG, ft_strlen(EXIT_MSG));
	}
	return (0);
}
