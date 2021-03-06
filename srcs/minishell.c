/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allanganoun <allanganoun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 08:37:43 by alganoun          #+#    #+#             */
/*   Updated: 2021/03/08 17:06:12 by allanganoun      ###   ########.fr       */
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
	printf("%d\n", fd);
	if (fd > 0)
	{
		while(ret > 0)
		{
			ret = get_next_line(fd, &line);
			write_output(line);
			free(line);
		}
		ret = get_next_line(fd, &line);
		write_output(line);
		free(line);
	}
	if (ret != 0)
		return (write_errors(1, str));
	return (0);
}

void	prcess_setid(t_prcess *prcess)
{
	char tmp[6];

	ft_bzero(tmp, 6);
	ft_memcpy(tmp, prcess->data, 6);
	if (strstr(prcess->data, "echo "))
		prcess->id = ID_ECHO;
	else if (strstr(prcess->data, " cd "))
		prcess->id = ID_CD;
	else if(strstr(prcess->data, "pwd"))
		prcess->id = ID_PWD;
	else if(strstr(prcess->data, "export"))
		prcess->id = ID_EXPORT;
	else if(strstr(prcess->data, "unset"))
		prcess->id = ID_UNSET;
	else if(strstr(prcess->data, "env"))
		prcess->id = ID_ENV;
	else
		prcess->id = ID_BIN;
}

void	init_cmds(t_cmd **cmd)
{
	int i;
	t_prcess *current;
	t_prcess *prcess;

	i = 0;
	current = NULL;
	while ((*cmd)->cmdline[i] != NULL)
	{ 
		current = ft_prcessnew((*cmd)->cmdline[i]);
		ft_prcessadd_back(&((*cmd)->prcess), current);
		prcess_setid(current);
		i++;
	}
	/*TESTEUR: AFFICHER LES COMMANDES DANS CHAQUE ELEMENT DE LA LISTE CHAINÉE
	while (prcess)
	{
		printf("[ %s ]<%d>\n", prcess->data, prcess->id);
		prcess = prcess->next;
	}*/
}

/*void		init_parser_cmd_ptr(int (*f[1])(t_cmd *))
{
	//f[0] = &cmd_echo;
	//f[1] = &cmd_cd;
	f[0] = &cmd_pwd;
	//f[3] = &cmd_export;
	//f[4] = &cmd_unset;
	//f[5] = &cmd_env;
	//f[6] = &cmd_bin;
}

int exec_prcess(t_cmd *cmd)
{
	int (*f[1])(t_cmd *);

	f[cmd->cmd_id](cmd);
	return (0);
}*/

int		input_process(char *line, t_cmd **cmd)
{
	int			i;
	t_prcess	*current;
	i = 0;
	if (((*cmd)->cmdline = ft_split(line, ';')) == NULL)
		return (write_errors(3, NULL));
	init_cmds(cmd);
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
	if (display_txt("banner.txt") == -1)
		return (-1);
	while(ret != 0)
	{
		write(1, "[minishell-1.0$ ", 16);
		get_next_input(&line);
		if (input_process(line, &cmd) == -1)
			return(-1);
		safe_free(&line);
	}
	safe_free(&line);
	safe_free((char **)&cmd);
	return (0);
}
