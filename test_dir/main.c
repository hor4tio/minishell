/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 08:53:55 by alganoun          #+#    #+#             */
/*   Updated: 2021/02/22 16:33:54 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main()
{

	//int ret;
	char *line;

	line = "coucouc";
	//printf("%d\n", word_count(line));
	//help for PWD
	//char buffer[PATH_MAX];
	//char *str;
//
	//if (getcwd(buffer, sizeof(buffer)) != NULL)
	//	printf("PATH = %s", buffer);
	printf("%d\n", ft_strcmp(NULL, line));
	return (0);
}
