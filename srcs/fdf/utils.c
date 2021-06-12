/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:38:06 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/12 01:29:31 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	word_count(char **str)
{
	int i;
	
	i = 0;
	while(str[i])
		i++;
	return (i);	
}

void	p_error(char *s)
{
	ft_putstr_fd("\x1b[31mError\n", 1);
	ft_putstr_fd(s, 1);
	write(1, "\n", 1);
	exit(0);
}