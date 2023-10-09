/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:19:50 by jolecomt          #+#    #+#             */
/*   Updated: 2023/10/09 14:26:48 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int     ft_atoi(char*);
void	ft_send_bits(int , char );

char    *ft_addchar_tobuff(char *buffer , char i);
size_t  ft_strlen(char *buffer);
char	*ft_itoa(int pid);


#endif