/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:55:25 by eric              #+#    #+#             */
/*   Updated: 2022/12/13 09:40:59 by eholzer          ###   ########.fr       */
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

	i = 0;
	bin = char_to_bin(c);
	while (i < 8)
	{
		if (bin[i] == '0')
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(100);
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
	(void) ac;
	(void) av;

	send_str(ft_atoi(av[1]), av[2]);
}
