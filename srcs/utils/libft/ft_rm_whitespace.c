/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:31:10 by alganoun          #+#    #+#             */
/*   Updated: 2021/01/29 09:31:39 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void		ft_rm_whitespace(char **str)
{
	while (((*str)[0] >= 9 && (*str)[0] <= 13) || (*str)[0] == 32)
		(*str)++;
}
