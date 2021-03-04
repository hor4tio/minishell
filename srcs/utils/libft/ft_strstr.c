/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoufi <musoufi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:51:40 by musoufi           #+#    #+#             */
/*   Updated: 2021/03/04 11:53:45 by musoufi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strstr(const char *haystack, const char *needle)
{
    size_t  i;
    size_t  j;
    char    *str;

    i = 0;
    str = (char *)haystack;
    if (!(*needle))
            return (str);
    while (haystack[i])
    {
            j = 0;
            while (needle[j] == haystack[i + j])
            {
                    if (needle[j + 1] == '\0')
                            return (str);
                    j++;
            }
            str++;
            i++;
    }
    return (NULL);
}