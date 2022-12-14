/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:13:11 by eric              #+#    #+#             */
/*   Updated: 2022/12/14 09:12:54 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	power(int n, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	while (power)
	{
		res *= n;
		power--;
	}
	return (res);
}

int	bin_to_char(char *bin)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (i < 8)
	{
		if (bin[7 - i] == '1')
		{
			res += power(2, i);
		}
		i++;
	}
	return (res);
}

void	sig_handler(int signum)
{
	static int	bit;
	static char	bin[8];
	char		c;

	if (signum == SIGUSR1)
		bin[bit] = '0';
	else if (signum == SIGUSR2)
		bin[bit] = '1';
	bit++;
	if (bit == 8)
	{
		c = bin_to_char(bin);
		bit = 0;
		ft_printf("%c", c);
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("> Server's Process ID (PID): %d\n", pid);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
