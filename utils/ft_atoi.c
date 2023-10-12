/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:39:41 by jolecomt          #+#    #+#             */
/*   Updated: 2023/10/09 13:57:34 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	value;
	int	puissance;

	i = 1;
	value = 0;
	puissance = 1;
	while (str[i] != '\0')
	{
		puissance *= 10;
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		value += (str[i] - '0' ) * puissance;
		puissance /= 10;
		i++;
	}
	return (value);
}
