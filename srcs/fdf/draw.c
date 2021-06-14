/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 21:04:49 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/14 18:14:35 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
**
**
**
*/

double	mod(double a)
{
	if (a < 0)
		return(-a);
	else
		return(a);
}

double max_n(double a, double b)
{
	if (a > b)
		return(a);
	else
		return(b);
}

/* *x =(*x + *y) * sin(0.523599); look up
	*y = (*x - *y) * cos(0.523599)- z; */

void rotate(double *x, double *y, t_fdf **fdf)
{
	double x_d;
	x_d = *x;
	*x = ( x_d  * cos(-(*fdf)->cam->rotspeed)) - *y * sin(-(*fdf)->cam->rotspeed);
	*y = ( x_d  * sin(-(*fdf)->cam->rotspeed)) + *y * cos(-(*fdf)->cam->rotspeed);
}
void isometric(double *x, double *y, int z, t_fdf **fdf)
{
	(void)fdf;
	*x = (*x - *y) * cos((*fdf)->cam->angle);
	*y = (*x + *y) * sin((*fdf)->cam->angle) - z;
}

void	bresenham(double x1, double y1, double x2, double y2, t_fdf **fdf)
{
	double x_step;
	double y_step;
	int	max;
	int z1;
	int z2;

	z1 = (*fdf)->map->table[(int)y1][(int)x1] * (*fdf)->map->zoom;
	z2 = (*fdf)->map->table[(int)y2][(int)x2] * (*fdf)->map->zoom;
	(*fdf)->map->color = (z1 || z2) ? 0xff00ff : 0xFFFFFF;
	x1 *= (*fdf)->map->zoom;
	x2 *= (*fdf)->map->zoom;
	y1 *= (*fdf)->map->zoom;
	y2 *= (*fdf)->map->zoom;
	
	

	if((*fdf)->cam->plane == 0)
	{
		isometric(&x1, &y1, z1, fdf);
		isometric(&x2, &y2, z2, fdf);
		
	}

	rotate(&x1, &y1, fdf);
	rotate(&x2, &y2, fdf);

	 x1 += (*fdf)->cam->dir_x;
	 y1 += (*fdf)->cam->dir_y;
	 x2 += (*fdf)->cam->dir_x;
	 y2 += (*fdf)->cam->dir_y;

	x_step = x2 - x1;
	y_step = y2 - y1;
	
	max = max_n(mod(x_step), mod(y_step));
	 x_step /= max;
	 y_step /= max;
	
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		if(y1 >= (*fdf)->data->winy || y1 < 0 || x1 > (*fdf)->data->winx || x1 < 0 )
		return ;		
		my_mlx_pixel_put(*fdf, x1, y1, (*fdf)->map->color);
		x1 += x_step;
		y1 += y_step;
	}
}

int draw(t_fdf **fdf)
{
	int x;
	int y;

	y = 0;
	while(y < (*fdf)->map->y )
	{
		x = 0;
		while (x < (*fdf)->map->x)
		{	
			if (x < (*fdf)->map->x - 1)
				bresenham(x, y, x + 1, y, fdf);
			if (y < (*fdf)->map->y - 1)
				bresenham(x, y, x, y + 1, fdf);
			x++;
		}
		y++ ;
	}
	return (1);
}