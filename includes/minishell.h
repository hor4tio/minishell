/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 08:54:52 by alganoun          #+#    #+#             */
/*   Updated: 2021/02/09 09:24:58 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BANNER		1
# define BUFFER_SIZE 1024
# define EXIT_MSG	"\n[Process completed]"

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include "../srcs/utils/libft/libft.h"


typedef struct	s_cmd
{
	char **cmdline;
	char *path;
}				t_cmd;

/*------------UTILS---------------*/
int			get_next_line(int fd, char **line);
int			get_next_input(char **line);
int			write_errors(int option, char *str);
size_t		ft_strlen(const char *str);
ssize_t		write_output(char *str);
char		*get_next_word(char **line);
int			display_text(char *str);
int			pwd_process();
int			word_count(char *str);
char		**free_tab(char **tab, int count);
int			write_exec_errors();

#endif
