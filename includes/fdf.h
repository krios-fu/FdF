/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:12:48 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/12 22:19:46 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_
# define FDF_
# include "../srcs/libft/libft.h"
# include "../srcs/gnl/get_next_line_bonus.h"
# include "../srcs/minilibx/mlx.h"
# include <math.h>

/* Struct data map */
typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
	int				up_switch;
	int				down_switch;
	int				left_switch;
	int				right_switch;
	int				color;
	int				arg;
}					t_data;

typedef struct	s_map
{
	int	color;
	int **table;
	int x;
	int y;
	int zoom;
}				t_map;

/* Data center */

typedef struct	s_fdf
{
	t_map		*map;
	t_data		*data;
}				t_fdf;

/* Map */

int		word_count(char **str);
void	fiil_map(char *file, t_fdf **fdf);
void	print_map(t_fdf **fdf);
void	check_map(char *file, t_fdf **fdf);


/* Error messages*/
void	p_error(char *s);

/* Draw */

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void	bresenham(float x1, float y1, float x2, float y2, t_fdf **fdf);
void	draw(t_fdf **fdf);
#endif