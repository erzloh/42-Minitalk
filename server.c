/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:13:11 by eric              #+#    #+#             */
/*   Updated: 2022/12/13 09:56:10 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_bin;

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
		/* if (bin[i] == '1')
			printf("1");
		else if (bin[i] == '0')
			printf("0"); */
		if (bin[7 - i] == '1')
		{
			res += power(2, i);
		}
		i++;
	}
	return (res);
}

void	handle_sigusr1(int sig)
{
	(void) sig;
	/* int		len;
	char	*new_bin; */

	ft_putchar_fd('0', 1);
	/* if (!g_bin)
		len = 0;
	else
		len = ft_strlen(g_bin);
	new_bin = malloc(sizeof(char) * len + 1);
	ft_memcpy(new_bin, g_bin, len);
	new_bin[len] = '0';
	free(g_bin);
	g_bin = new_bin;
	if (len + 1 == 8)
	{
		ft_printf("%c", bin_to_char(g_bin));
		free(g_bin);
		g_bin = NULL;
	} */
}

void	handle_sigusr2(int sig)
{
	(void) sig;
	/* int		len;
	char	*new_bin; */

	ft_putchar_fd('1', 1);
	/* if (!g_bin)
		len = 0;
	else
		len = ft_strlen(g_bin);
	new_bin = malloc(sizeof(char) * len + 1);
	ft_memcpy(new_bin, g_bin, len);
	new_bin[len] = '1';
	free(g_bin);
	g_bin = new_bin;
	if (len + 1 == 8)
	{
		ft_printf("%c", bin_to_char(g_bin));
		free(g_bin);
		g_bin = NULL;
	} */
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
	// struct sigaction	sa;

	pid = getpid();
	ft_printf("Server's Process ID (PID): %d\n", pid);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	/* sa.sa_handler = &sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL); */
	while (1)
		pause();
	return (0);
}
