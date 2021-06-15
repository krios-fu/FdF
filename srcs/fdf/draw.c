/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 21:04:49 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/15 21:37:45 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	isometric	(double *x, double *y, int z, t_fdf **fdf)
{
	int	tmp_x;

	tmp_x = *x;
	if ((*fdf)->cam->plane == 0)
	{
		*x = (tmp_x + *y) * sin(0.8) * 2;
		*y = (*y - tmp_x) * cos(0.8) - z;
	}
}

static void	draw_line(t_breshman *brs, t_fdf **fdf, int color)
{
	double	max;

	rotate(&brs->x1, &brs->y1, fdf);
	rotate(&brs->x2, &brs->y2, fdf);
	set_move(brs, fdf);
	brs->x_step = brs->x2 - brs->x1;
	brs->y_step = brs->y2 - brs->y1;
	max = max_n(fabs(brs->x_step), fabs(brs->y_step));
	brs->x_step /= max;
	brs->y_step /= max;
	while ((int)(brs->x1 - brs->x2) || (int)(brs->y1 - brs->y2))
	{
		if (brs->y1 >= (*fdf)->data->winy || brs->y1 < 0
			|| brs->x1 > (*fdf)->data->winx || brs->x1 < 0 )
			return ;
		my_mlx_pixel_put(*fdf, brs->x1, brs->y1, color);
		brs->x1 += brs->x_step;
		brs->y1 += brs->y_step;
	}
}

static void	bresenham(t_breshman *brs, t_fdf **fdf)
{
	int	z1;
	int	z2;
	int	color;

	if ((*fdf)->map->table[(int)brs->y1][(int)brs->x1] >= 0)
	{
		z1 = ((*fdf)->map->table[(int)brs->y1][(int)brs->x1]
				* (*fdf)->map->eleva) * (*fdf)->map->zoom;
		z2 = ((*fdf)->map->table[(int)brs->y2][(int)brs->x2]
				* (*fdf)->map->eleva) * (*fdf)->map->zoom;
	}
	else
	{
		z1 = ((*fdf)->map->table[(int)brs->y1][(int)brs->x1]
				* -(*fdf)->map->eleva) * (*fdf)->map->zoom;
		z2 = ((*fdf)->map->table[(int)brs->y2][(int)brs->x2]
				* -(*fdf)->map->eleva) * (*fdf)->map->zoom;
	}
	color = (*fdf)->map->color[(int)brs->y1][(int)brs->x1];
	set_zoom(brs, fdf);
	isometric(&brs->x1, &brs->y1, z1, fdf);
	isometric(&brs->x2, &brs->y2, z2, fdf);
	draw_line(brs, fdf, color);
}

static void	set_pixel(t_breshman *brs, t_fdf **fdf)
{
	if (brs->j < (*fdf)->map->x - 1)
	{
		brs->x1 = brs->j;
		brs->y1 = brs->i;
		brs->y2 = brs->i;
		brs->x2 = (brs->x1 + 1);
		bresenham(brs, fdf);
	}
	if (brs->i < (*fdf)->map->y - 1)
	{
		brs->x1 = brs->j;
		brs->y1 = brs->i;
		brs->x2 = brs->j;
		brs->y2 = (brs->y1 + 1);
		bresenham(brs, fdf);
	}
}

void	draw(t_fdf **fdf)
{
	t_breshman	brs;

	brs.i = 0;
	while (brs.i < (*fdf)->map->y)
	{
		brs.j = 0;
		while (brs.j < (*fdf)->map->x)
		{	
			set_pixel(&brs, fdf);
			brs.j++;
		}
		brs.i++;
	}
}
