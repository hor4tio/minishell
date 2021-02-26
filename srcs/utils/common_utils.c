/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:00:40 by alganoun          #+#    #+#             */
/*   Updated: 2021/02/26 16:53:10 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		word_count(char *str)
{
	int i;
	int nb;
	int	found;

	i = 0;
	nb = 0;
	found = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			found = 0;
		else if (found == 0)
		{
			nb++;
			found = 1;
		}
		i++;
	}
	return (nb);
}

char	**cmd_parser(char *line, int nb)
{
	char	**tab;
	char	*word;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if(!(tab = (char **)malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	word = NULL;
	while (line[i])
	{
		while (line[i] && (line[i] >= 9 || line[i] <= 13) && line[i] == 32)
			i++;
		if (!(word = get_next_word(&(line[i])))
			|| !(tab[j] = ft_strdup(word)))
		{
			free_tab(&tab, j + 1);
			return (NULL);
		}
		printf("%s\n", tab[j]);
		i =  i + ft_strlen(word);
		safe_free(&word);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

int		cmd_analyzer(char **tab, t_cmd **cmd)
{

}
