/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:37:29 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/16 20:59:21 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_bit_rgb(unsigned char *s, int i)
{
	s[0] = (unsigned char)i;
	s[1] = (unsigned char)(i >> 8);
	s[2] = (unsigned char)(i >> 16);
	s[3] = (unsigned char)(i >> 24);
}

void	ft_bmp_cabezera(t_fdf **fdf, int fd, int ps)
{
	unsigned char	header[54];
	int				filesize;

	filesize = 54 + ((*fdf)->data->winx * 3 * (*fdf)->data->winy)
		+ (ps * (*fdf)->data->winx);
	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	ft_bit_rgb(header + 2, filesize);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	ft_bit_rgb(header + 18, (*fdf)->data->winx);
	ft_bit_rgb(header + 22, -(*fdf)->data->winy);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(32);
	write(fd, header, 54);
	write(fd, (*fdf)->data->addr, (*fdf)->data->winx * (*fdf)->data->winy * 4);
}

int	ft_screenshot(t_fdf **fdf)
{
	int	fd;
	int	padsize;

	padsize = (4 - ((*fdf)->data->winx * 3) % 4) % 4;
	write(1, "\n\x1b[36m[Screenshot] \t Route: ./fdf.bmp\n", 39);
	fd = open("./fdf.bmp", O_WRONLY | O_CREAT, S_IRWXU | O_TRUNC | O_APPEND);
	if (!fd)
		write(1, "\x1b[36mScreenshot could not be created!", 40);
	ft_bmp_cabezera(fdf, fd, padsize);
	return (1);
}
