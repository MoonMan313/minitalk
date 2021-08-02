/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:11:33 by cdionna           #+#    #+#             */
/*   Updated: 2021/07/08 19:19:12 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

int	decimal_conversion(char *buf)
{
	int	num;
	int	two;
	int	i;

	num = 0;
	two = 1;
	i = 7;
	while (i >= 0)
	{
		if (buf[i] == '1')
			num += two;
		two *= 2;
		i--;
	}
	return (num);
}

void	receive_message(int sig, siginfo_t *siginfo, void *context)
{
	static char	*buf;
	char		c;

	if (!buf)
		buf = ft_strdup("");
	if (sig == SIGUSR1)
		buf = ft_strjoin(buf, "1", 1);
	if (sig == SIGUSR2)
		buf = ft_strjoin(buf, "0", 1);
	if (ft_strlen(buf) == 8)
	{
		c = (char)decimal_conversion(buf);
		free(buf);
		buf = NULL;
		if (c == 0)
		{
			kill(siginfo->si_pid, SIGUSR1);
			(void)context;
			write(1, "\n", 2);
		}
		else
			write(1, &c, 1);
	}
}

int	main(void)
{
	struct sigaction	act;
	sigset_t			set;
	char				*pid;

	ft_memset(&act, 0, sizeof(act));
	act.sa_sigaction = &receive_message;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	act.sa_mask = set;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	pid = ft_itoa(getpid());
	ft_putstr("PID = ");
	ft_putstr(pid);
	ft_putstr("\n");
	free(pid);
	while (1)
		pause();
	return (0);
}
