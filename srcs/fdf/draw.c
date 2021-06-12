/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 21:04:49 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/13 01:34:06 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
**
**
**
*/

float	mod(float a)
{
	if (a < 0)
		return(-a);
	else
		return(a);
}

float max_n(float a, float b)
{
	if (a > b)
		return(a);
	else
		return(b);
}

void isometric(float *x, float *y, int z)
{
	*x =(*x - *y) * sin(0.8);
	*y = (*x + *y) * cos(0.8) - z;
}

void	bresenham(float x1, float y1, float x2, float y2, t_fdf **fdf)
{
	float x_step;
	float y_step;
	int	max;
	int z1;
	int z2;

	 z1 = (*fdf)->map->table[(int)y1][(int)x1];
	 z2 = (*fdf)->map->table[(int)y2][(int)x2];
	(*fdf)->map->color = (z1 || z2) ? 0x39FF14 : 0xFFFFFF;
	x1 *= (*fdf)->map->zoom;
	x2 *= (*fdf)->map->zoom;
	y1 *= (*fdf)->map->zoom;
	y2 *= (*fdf)->map->zoom;
	
	
	isometric(&x1, &y1, z1);
	isometric(&x2, &y2, z2);

	 x1 += 200;
	 y1 += 150;
	 x2 += 200;
	 y2 += 150;

	x_step = x2 - x1;
	y_step = y2 - y1;
	
	max = max_n(mod(x_step), mod(y_step));
	 x_step /= max;
	 y_step /= max;
	
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		my_mlx_pixel_put(*fdf, x1, y1, (*fdf)->map->color);
		x1 += x_step;
		y1 += y_step;
	}
}

void draw(t_fdf **fdf)
{
	int x;
	int y;

	y = 0;
	while(y < (*fdf)->map->y -1)
	{
		x = 0;
		while (x < (*fdf)->map->x -1)
		{	
			bresenham(x, y, x, y + 1, fdf);
			bresenham(x, y, x + 1, y, fdf);
			x++;
		}
		y++ ;
	}
}