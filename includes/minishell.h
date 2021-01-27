/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 08:54:52 by alganoun          #+#    #+#             */
/*   Updated: 2021/01/27 14:39:38 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BANNER		1
# define BUFFER_SIZE 1024
# define EXIT_MSG	"Exiting minishell..."

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>


/*------------UTILS---------------*/
int			get_next_line(int fd, char **line);
int			get_next_input(char **line);
int			write_errors(int option);
size_t		ft_strlen(const char *str);
ssize_t		write_output(char *str);
int			ft_strcmp(char *s1, char *s2);

#endif
