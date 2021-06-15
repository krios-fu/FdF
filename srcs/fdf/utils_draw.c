/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 21:34:10 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/15 23:31:19 by krios-fu         ###   ########.fr       */
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

void	rotate(double *x, double *y, t_fdf **fdf)
{
	double	x_d;

	x_d = *x;
	*x = (x_d * cos(-(*fdf)->cam->rotspeed)) - *y * sin(-(*fdf)->cam->rotspeed);
	*y = (x_d * sin(-(*fdf)->cam->rotspeed)) + *y * cos(-(*fdf)->cam->rotspeed);

	/* matriz de  rotacion en y en 3d */
}
