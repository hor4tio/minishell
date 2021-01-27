/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 08:53:55 by alganoun          #+#    #+#             */
/*   Updated: 2021/01/25 13:19:58 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main()
{

	int ret;
	char *line;

	while((ret = get_next_line(0, line)) != 0)
	//help for PWD
	//char buffer[PATH_MAX];
	//char *str;
//
	//if (getcwd(buffer, sizeof(buffer)) != NULL)
	//	printf("PATH = %s", buffer);
	return (0);
}
