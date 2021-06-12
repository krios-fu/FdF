/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:03:59 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/13 01:25:35 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char *dst;

	dst = (char *)fdf->data->addr + (y * fdf->data->line_lenght + x
		* (fdf->data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int start(t_fdf **fdf)
{
	 check_map("./test_maps/42.fdf", fdf);
	 fiil_map("./test_maps/42.fdf", fdf);
	 //print_map(fdf);

	draw(fdf);
	
	mlx_put_image_to_window((*fdf)->data->mlx,
		(*fdf)->data->win, (*fdf)->data->img, 0, 0);

	return (1);
}

int main(int argc, char *argv[])
{
	t_fdf *fdf;
	t_map map;
	t_data data;
	
	(void)argv;
	(void)argc;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->map = &map;
	fdf->map->zoom = 25;
	fdf->data = &data;
	fdf->data->arg = argc;
	fdf->data->mlx = mlx_init();
	fdf->data->win =
		mlx_new_window(fdf->data->mlx, 720, 480, "FdF");
	fdf->data->img = mlx_new_image(fdf->data->mlx, 720, 480);
	fdf->data->addr = mlx_get_data_addr(fdf->data->img, &fdf->data->bits_per_pixel,
	 &fdf->data->line_lenght, &fdf->data->endian);
	//mlx_hook(fdf->data->win, 2, (1L << 0), start, fdf);
	start(&fdf);
	//mlx_loop_hook(fdf->data->mlx, start, &fdf);
	mlx_loop(fdf->data->mlx);
	// check_map("./test_maps/42.fdf", &fdf);
	// fiil_map("./test_maps/42.fdf", &fdf);
	// print_map(&fdf);
	return(0);
}