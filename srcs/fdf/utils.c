/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:38:06 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/15 23:05:05 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	word_count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
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

int	str_hexa_to_int(char *str)
{
	int	num;
	int	i;

	i = 0;
	if (!str)
		return (0xffffff);
	while (str[i] && i < 7)
	{
		if (str[i] == ' ')
			return (num);
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 16 + str[i] - '0';
		if (str[i] >= 'a' && str[i] <= 'f')
			num = num * 16 + str[i] - 'a' + 10;
		if (str[i] >= 'A' && str[i] <= 'F')
			num = num * 16 + str[i] - 'A' + 10;
		i++;
	}
	return (num);
}
