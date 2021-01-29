/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 08:53:55 by alganoun          #+#    #+#             */
/*   Updated: 2021/01/27 14:55:01 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main()
{

	int ret;
	char *line;

	line = "                       					coucou";

	check_whitespace(&line);
	printf("%s\n", line);
	//help for PWD
	//char buffer[PATH_MAX];
	//char *str;
//
	//if (getcwd(buffer, sizeof(buffer)) != NULL)
	//	printf("PATH = %s", buffer);
	return (0);
}
