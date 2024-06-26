/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:19:33 by jolecomt          #+#    #+#             */
/*   Updated: 2023/10/18 22:45:23 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h" 

void	print_buffer(char *buffer)
{
	int	i;

	i = 0;
	if (buffer == NULL)
		write(1, "\0", 1);
	else
	{
		while (buffer[i] != '\0')
		{
			write(1, &buffer[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

void	print_pid(int pid)
{
	char	*printable_pid;

	write(1, "PID is -> ", 11);
	printable_pid = ft_itoa(pid);
	print_buffer(printable_pid);
	free(printable_pid);
}

void	ft_handler(int signal)
{
	static int	bit = 0;
	static int	i = 0;
	static char	*buffer = NULL;

	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == '\0')
		{
			print_buffer(buffer);
			bit = 0;
			i = 0;
			free(buffer);
			buffer = NULL;
		}
		else
		{
			buffer = ft_addchar_tobuff(buffer, i);
			bit = 0;
			i = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
		return (0);
	pid = getpid();
	print_pid(pid);
	usleep(1000);
	while (1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0);
}
