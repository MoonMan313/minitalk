/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:38:51 by cdionna           #+#    #+#             */
/*   Updated: 2021/07/08 18:07:27 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	binary_translation(int pid, char c)
{
	int	mask;

	mask = 128;
	while (mask >= 1)
	{
		if (mask & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		mask /= 2;
		usleep(50);
	}
}

void	sending_message(int pid, char *str)
{
	char	c;

	while (*str)
	{
		c = *str;
		binary_translation(pid, c);
		str++;
	}
	binary_translation(pid, 0);
}

int	check_param_pid(char *str)
{
	str = ft_isspase(str);
	while (*str && *str < 58 && *str > 47)
		str++;
	str = ft_isspase(str);
	if (*str != '\0')
		return (1);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3 || check_param_pid(argv[1]))
	{
		ft_putstr("Enter: ./client [server pid] [message]\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	sending_message(pid, argv[2]);
}
