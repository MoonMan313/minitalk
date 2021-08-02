/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:33:45 by cdionna           #+#    #+#             */
/*   Updated: 2021/07/07 16:39:06 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
void	ft_putstr(char *s);
char	*ft_itoa(int n);
char	*ft_isspase(const char *s);
char	*ft_strjoin(char *dst, char *src, int len);
char	*ft_strdup(char *s1);
void	*ft_memset(void *b, int c, size_t len);

#endif