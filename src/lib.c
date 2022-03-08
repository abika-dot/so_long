/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:16:46 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/08 23:27:35 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (needle[j] && haystack[i] && i < n)
	{
		if (haystack[i] == needle[j])
			j++;
		else if ((haystack[i] != needle[j]) && j != 0)
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	if (needle[j] != '\0')
		return (NULL);
	else
		return ((char *)(&haystack[i - j]));
}
