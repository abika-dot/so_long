/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:08:12 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/12 22:26:15 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
char	**d_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (str);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (src[count])
		count++;
	if (dstsize == 0)
		return (count);
	while (src[i] && dstsize != 0 && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}
static char	**freed(char **spl, int index)
{
	int	i;

	i = 0;
	if (index <= 0)
	{
		free(spl);
		return (NULL);
	}
	while (i < index)
	{
		free(spl[i]);
		i++;
	}
	free(spl);
	return (NULL);
}

static	int	rows(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	j++;
	return (j);
}

static	char	**alocation(char **spl, const char *s, char c)
{
	int	i;
	int	j;
	int	a;

	a = 0;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i + j] && s[i + j] != c)
			j++;
		spl[a] = malloc(j * sizeof(char) + 1);
		if (!spl[a])
			return (freed(spl, a));
		i = i + j;
		j = 0;
		a++;
	}
	spl[a] = NULL;
	return (spl);
}

static	char	**endl(char **spl, const char *s, char c)
{
	int	i;
	int	j;
	int	a;

	a = 0;
	i = 0;
	j = 0;
	while (s[i] != '\0' )
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i + j] && s[j + i] != c)
			j++;
		ft_strlcpy(spl[a], s + i, j + 1);
		i = i + j;
		j = 0;
		a++;
	}
	return (spl);
}

char	**ft_split(char const *s, char c)
{
	int		a;
	char	**spl;

	if (!s)
		return (NULL);
	a = rows(s, c);
	if (a == 0)
		return (NULL);
	spl = malloc(a * sizeof(char *));
	if (!spl)
		return (NULL);
	spl = alocation(spl, s, c);
	if (spl == NULL)
		return (NULL);
	spl = endl(spl, s, c);
	return (spl);
}
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && n > i)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
