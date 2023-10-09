/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:19:33 by jolecomt          #+#    #+#             */
/*   Updated: 2023/10/09 14:52:10 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h" 

void	print_buffer(char *buffer)
{
	int i;
	
	i = 0;
	while (buffer[i] != '\0')
	{
		write(1, &buffer[i], 1);
		i++;
	}
	// free(buffer);
}

void	print_pid(int pid)
{
	char *printable_pid;
	
	write(1, "PID is -> ", 11);
	printable_pid = ft_itoa(pid);
	print_buffer(printable_pid);
	write(1, "\n", 1);
}

void    ft_handler(int signal)
{
	// need to init 2 static bit and i;
	// compare sig get , after getting 8 bits, a char and put it in a buffer until '\0' is send.
	static int	bit;
	static int	i;
	char		*buffer;

	if (buffer == NULL)
		buffer = malloc(sizeof(char));
	if (signal == SIGUSR1)
		i |= (1 << bit);   
	bit++;
	if (bit == 8)
	{
		if (i == '\0')
			print_buffer(buffer);
		else
		{
			ft_addchar_tobuff(buffer , i);
			bit = 0;
			i = 0;
		}
	}
}


int main(int argc, char **argv)
{
	int     pid;

	
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