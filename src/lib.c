/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:16:46 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/10 19:47:51 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}

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

int	ft_lstsize(t_list *lst)
{
	int	i;
    t_list *temp;
    
    temp = lst;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
static char	*zerorule(char *ss)
{
	ss[0] = 0;
	return (ss);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ss;
	unsigned int	i;
	unsigned int	sl;

	i = 0;
	if (!s)
		return (NULL);
	sl = ft_strlen(s);
	if (len > sl)
		len = sl;
	ss = malloc(len * sizeof(char) + 1);
	if (!ss)
		return (NULL);
	if (start > sl)
		return (zerorule(ss));
	while (s[start] && i < len)
	{
		ss[i] = s[start];
		i++;
		start++;
	}
	ss[i] = 0;
	return (ss);
}