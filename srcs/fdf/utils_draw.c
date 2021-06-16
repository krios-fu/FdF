/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 21:34:10 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/16 03:06:21 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	set_zoom(t_breshman *brs, t_fdf **fdf)
{
	brs->x1 *= (*fdf)->map->zoom;
	brs->x2 *= (*fdf)->map->zoom;
	brs->y1 *= (*fdf)->map->zoom;
	brs->y2 *= (*fdf)->map->zoom;
}

void	set_move(t_breshman *brs, t_fdf **fdf)
{
	brs->x1 += (*fdf)->cam->dir_x;
	brs->y1 += (*fdf)->cam->dir_y;
	brs->x2 += (*fdf)->cam->dir_x;
	brs->y2 += (*fdf)->cam->dir_y;
}

double	max_n(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	rotate(t_breshman *brs, t_fdf **fdf)
{
	double x_d;
	x_d = brs->x1;
	// (void)fdf;
	brs->x1 += ((*fdf)->lst_y - brs->y1) / 200.0f;
	brs->y1 -= ((*fdf)->lst_x + brs->x1) / 200.0f;

	/* matriz de  rotacion en y en 3d */
}
