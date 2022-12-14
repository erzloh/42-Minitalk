/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:55:25 by eric              #+#    #+#             */
/*   Updated: 2022/12/14 12:51:32 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*calloc_char(size_t count, size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = '0';
		i++;
	}
	return ((void *)ptr);
}

char	*char_to_bin(char c)
{
	int		n;
	int		p;
	char	*bin;

	bin = calloc_char(8, sizeof(char));
	if (!bin)
		return (NULL);
	if (c == 0)
		return (bin);
	while (c != 0)
	{
		n = 1;
		p = 0;
		while (c >= n)
		{
			n *= 2;
			p++;
		}
		c -= (n / 2);
		bin[8 - p] = '1';
	}
	return (bin);
}

void	send_char(int pid, char c)
{
	int		i;
	char	*bin;
	int		delay;

	i = 0;
	bin = char_to_bin(c);
	delay = 100;
	while (i < 8)
	{
		if (bin[i] == '0')
		{
			kill(pid, SIGUSR1);
			usleep(delay);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(delay);
		}
		i++;
	}
	free(bin);
}

void	send_str(int pid, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		send_char(pid, str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	pid = ft_atoi(av[1]);
	if (ac < 3 || ac > 3)
	{
		ft_printf("Error: make sure you enter your arguments as follow: ");
		ft_printf("<PID> <message>");
		return (1);
	}
	send_str(pid, av[2]);
	send_char(pid, '\n');
}
