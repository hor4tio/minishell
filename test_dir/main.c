/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 08:53:55 by alganoun          #+#    #+#             */
/*   Updated: 2021/02/09 08:31:10 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main()
{

	int ret;
	char *line;

	line = "";
	printf("%d\n", word_count(line));
	//help for PWD
	//char buffer[PATH_MAX];
	//char *str;
//
	//if (getcwd(buffer, sizeof(buffer)) != NULL)
	//	printf("PATH = %s", buffer);
	return (0);
}
