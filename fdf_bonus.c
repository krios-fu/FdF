/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:27:04 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/16 21:00:32 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"



void print_star(t_fdf **fdf)
{
	int i;

	i = 0;
	if((*fdf)->cam->keycode->sp)
	{
		while (i < 200)
		{
			mlx_string_put((*fdf)->data->mlx, (*fdf)->data->win,
				rand () % 2048 , rand () %  1080  , 0xffc700, ".");
			mlx_string_put((*fdf)->data->mlx, (*fdf)->data->win, rand () % 2048,
				rand () % 1080 , 0xffffff, ".");
			i++;
		}
	}
}

void	print_menu(t_fdf **fdf)
{
	char *menu;
	char *data;

	menu = "Move picture: W, S, D, A";
	mlx_string_put((*fdf)->data->mlx, (*fdf)->data->win, 42, 42, 0x03fc35, menu);
	menu = "Zoom: Up, Dowm ";
	mlx_string_put((*fdf)->data->mlx, (*fdf)->data->win, 42, 62, 0xFFFFFF, menu);
	menu = "Rotation: Rigth, Left";
	mlx_string_put((*fdf)->data->mlx, (*fdf)->data->win, 42, 82, 0x03fc35, menu);
	menu = "2D, 3D: P, I";
	mlx_string_put((*fdf)->data->mlx, (*fdf)->data->win, 42, 102, 0xFFFFFF, menu);
	menu = "Move Angle: Q, E";
	mlx_string_put((*fdf)->data->mlx, (*fdf)->data->win, 42, 122, 0x03fc35, menu);
	menu = "Mood Universe: SP";
	mlx_string_put((*fdf)->data->mlx, (*fdf)->data->win, 42, 142, 0xFFFFFF, menu);
	menu = "Screenshot: K";
	mlx_string_put((*fdf)->data->mlx, (*fdf)->data->win, 42, 162, 0x03fc35, menu);
	menu = "Zoom:";
	mlx_string_put((*fdf)->data->mlx, (*fdf)->data->win, 42, 380, 0x03fc35, menu);
	data = ft_itoa((*fdf)->map->zoom);
	mlx_string_put((*fdf)->data->mlx, (*fdf)->data->win, 44, 400, 0xFFFFFF, data);
	free(data);
	menu = "Rotation:";
	mlx_string_put((*fdf)->data->mlx, (*fdf)->data->win, 42, 420, 0x03fc35, menu);
	data = ft_itoa((*fdf)->cam->rotspeed);
	mlx_string_put((*fdf)->data->mlx, (*fdf)->data->win, 44, 440, 0xFFFFFF, data);
	free(data);
	menu = "Elevation:";
	mlx_string_put((*fdf)->data->mlx, (*fdf)->data->win, 42, 460, 0x03fc35, menu);
	data = ft_itoa((*fdf)->map->eleva);
	mlx_string_put((*fdf)->data->mlx, (*fdf)->data->win, 44, 480, 0xFFFFFF, data);
	free(data);
}

int start(t_fdf **fdf)
{	
	key_move(fdf);
	mlx_destroy_image((*fdf)->data->mlx, (*fdf)->data->img);
	(*fdf)->data->img = mlx_new_image((*fdf)->data->mlx, (*fdf)->data->winx, (*fdf)->data->winy);
	draw(fdf);
	mlx_put_image_to_window((*fdf)->data->mlx,
	(*fdf)->data->win, (*fdf)->data->img, 0, 0);
	print_star(fdf);
	print_menu(fdf);
	return(1);
}

static void	loop_fdf(t_fdf **fdf)
{
	draw(fdf);
	mlx_put_image_to_window((*fdf)->data->mlx,
		(*fdf)->data->win, (*fdf)->data->img, 0, 0);
	print_menu(fdf);
	mlx_hook((*fdf)->data->win, 2, (1L << 0), ft_keypress,fdf);
	mlx_hook((*fdf)->data->win, 3, (1L << 0), ft_keyrelease, fdf);
	mlx_hook((*fdf)->data->win, 17, (17L << 0), ft_exit, fdf);
	 mlx_loop((*fdf)->data->mlx);
}



int main(int argc, char *argv[])
{
	t_fdf *fdf;
	t_map map;
	t_data data;
	t_cam  cam;
	t_keycode keycode;
	
	if (argc != 2)
		p_error("Usage : ./test_maps/fdf <filename>");
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		p_error("Fail malloc");
	fdf->map = &map;
	fdf->cam = &cam;
	fdf->cam->keycode = &keycode;
	fdf->data = &data;
	fdf->data->winx = 2048;
	fdf->data->winy = 1080;
	set_var(&fdf);
	fill_check(&fdf, argv[1]);
	create_windows(&fdf);
	loop_fdf(&fdf);
	return(0);
}