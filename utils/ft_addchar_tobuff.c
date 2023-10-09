/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar_tobuff.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:32:57 by jolecomt          #+#    #+#             */
/*   Updated: 2023/10/09 14:54:30 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	*ft_addchar_tobuff(char *buffer, char i)
{
	char	*newbuf;
	int	strlen;
	
	size_t	n;

	if (buffer == NULL)
	{
		buffer = malloc(sizeof(char) * 2);
		buffer[0] = i;
		buffer[1] = '\0';
	}
	else
	{
		strlen = ft_strlen(buffer);
		newbuf = malloc(sizeof(char) * (strlen + 2));
		n = 0;
		while (buffer[n] != '\0')
		{
			newbuf[n] = buffer[n];
			n++;
		}
		newbuf[++n] = i;
		newbuf[++n] = '\0';
		// free(buffer);
	}
	return (newbuf);
}