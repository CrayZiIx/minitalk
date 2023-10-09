/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:12:02 by jolecomt          #+#    #+#             */
/*   Updated: 2023/10/09 14:53:58 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	lennb(int number)
{
	int	i;
	int	cpy;

	i = 0;
	cpy = number;
	if (cpy == 0)
		return (1);
	while(cpy != 0)
	{
		cpy /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int pid)
{
	int	len;
	int	i;
	char	*tmp;

	len = lennb(pid);
	tmp = malloc(sizeof(char) * (len + 1));
	tmp[len] = '\0';
	while (pid != 0)
	{
		tmp[len-1] = (pid % 10) + '0';
		pid /= 10;
		len--;
	}
	return (tmp);
}