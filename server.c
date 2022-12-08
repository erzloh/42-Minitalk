/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:13:11 by eric              #+#    #+#             */
/*   Updated: 2022/12/08 17:26:54 by eholzer          ###   ########.fr       */
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

int	main(void)
{
	int					pid;
	// struct sigaction	sa;
	//char	*bin = "00101010";

	pid = getpid();
	ft_printf("%d\n", pid);
	/* sa.sa_handler = &handle_sigusr1;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL); */
	signal(SIGUSR1, handle_sigusr1);
	signal(SIGUSR2, handle_sigusr2);

	//ft_printf("%d", bin_to_char(bin));

	while (1);
	return (0);
}
