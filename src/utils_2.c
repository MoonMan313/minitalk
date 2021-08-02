/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:28:29 by cdionna           #+#    #+#             */
/*   Updated: 2021/07/08 18:13:04 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

char	*ft_isspase(const char *s)
{
	while (*s && (*s == ' ' || *s == '\t' || *s == '\v'
			|| *s == '\r' || *s == '\n' || *s == '\f'))
		++s;
	return ((char *)s);
}

int	ft_atoi(const char *str)
{
	int	value;
	int	n_p;
	int	i;

	n_p = 1;
	value = 0;
	i = 0;
	str = ft_isspase(str);
	if (*str == '-')
		n_p = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str > 47 && *str < 58)
	{
		value = value * 10 + (int)(*str - 48);
		++str;
		++i;
		if (i > 19 && n_p > 0)
			return (-1);
		if (i > 19 && n_p < 0)
			return (0);
	}
	return (n_p * value);
}

int	ft_count(int d)
{
	int	j;

	j = 0;
	while (d != 0)
	{
		d = d / 10;
		j++;
	}
	return (j);
}

char	*ft_neg(int nb)
{
	int		n_len;
	char	*dup;

	n_len = ft_count(nb) + 1;
	dup = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!dup)
		return (0);
	dup[0] = '-';
	dup[n_len] = '\0';
	while (nb != 0 && n_len)
	{
		n_len--;
		dup[n_len] = (nb % 10) * (-1) + 48;
		nb = nb / 10;
	}
	return (dup);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*buf;

	if (n < 0)
		return (ft_neg(n));
	len = ft_count(n);
	if (n == 0)
		len = 1;
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (0);
	buf[len] = '\0';
	if (n == 0)
		buf[0] = 0 + 48;
	while (n != 0 && len)
	{
		len--;
		buf[len] = n % 10 + 48;
		n = n / 10;
	}
	return (buf);
}
