/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:40:49 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/16 20:59:13 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char *dst;

	dst = (char *)fdf->data->addr + (y * fdf->data->line_lenght + x
		* (fdf->data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		ft_exit(t_fdf **fdf)
{
	write(1, "\x1b[36mClose\n", 11);
	mlx_destroy_window((*fdf)->data->mlx, (*fdf)->data->win);
	exit(0);
}

void fill_check(t_fdf **fdf, char *str)
{
	check_map(str, fdf);
	fiil_map(str, fdf);
}

void	set_var(t_fdf	**fdf)
{
	
	(*fdf)->cam->keycode->w = 0;
	(*fdf)->cam->keycode->a = 0;
	(*fdf)->cam->keycode->s = 0;
	(*fdf)->cam->keycode->d = 0;
	(*fdf)->cam->keycode->zu = 0;
	(*fdf)->cam->keycode->zd = 0;
	(*fdf)->cam->keycode->rr = 0;
	(*fdf)->cam->keycode->rl = 0;
	(*fdf)->cam->keycode->p = 0;
	(*fdf)->cam->keycode->i = 0;
	(*fdf)->cam->keycode->sp = 0;
	(*fdf)->cam->rotspeed = 0.8;
	(*fdf)->cam->keycode->e = 0;
	(*fdf)->cam->keycode->q = 0;
	(*fdf)->cam->keycode->c = 0;
	(*fdf)->cam->plane = 0;
	(*fdf)->map->eleva = 1;
	(*fdf)->cam->keycode->x = 0;
	(*fdf)->cam->keycode->esc = 0;
	(*fdf)->map->zoom = 20;

}