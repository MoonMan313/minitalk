/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:59:07 by cdionna           #+#    #+#             */
/*   Updated: 2021/07/07 19:13:24 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	ft_putstr(char *s)
{
	write(0, s, ft_strlen(s));
}

char	*ft_strjoin(char *dst, char *src, int len)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = ft_strlen(dst) + len + 1;
	buf = (char *)malloc(j * sizeof(char));
	if (!buf)
		return (NULL);
	while (dst[i] != '\0')
	{
		buf[i] = dst[i];
		i++;
	}
	free(dst);
	j = 0;
	while (len != j)
	{
		buf[i + j + 1] = '\0';
		buf[i + j] = src[j];
		j++;
	}
	return (buf);
}

char	*ft_strdup(char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!dup)
		return (0);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = c;
		++i;
	}
	return (b);
}
