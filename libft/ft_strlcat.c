/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:17:02 by troxanna          #+#    #+#             */
/*   Updated: 2020/11/22 19:08:35 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t        ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t    i;
    int        j;
    size_t    dest_len;

    if (size == 0)
        return (ft_strlen(src));
    i = 0;
    j = 0;
    while (dest[i] && i < size)
        i++;
    dest_len = i;
    while (src[j] && i < size - 1)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    if (i < size)
        dest[i] = '\0';
    return (dest_len + ft_strlen(src));
}
