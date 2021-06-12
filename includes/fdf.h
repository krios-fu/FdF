/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:12:48 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/12 02:52:33 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_
# define FDF_
# include "../srcs/libft/libft.h"
# include "../srcs/gnl/get_next_line_bonus.h"
# include "../srcs/minilibx/mlx.h"

/* Struct data map */

typedef struct	s_map
{
	int	color;
	int **table;
	int x;
	int y;
}				t_map;

/* Data center */

typedef struct	s_fdf
{
	t_map		*map;
}				t_fdf;

/* Map */

int		word_count(char **str);
void	fiil_map(char *file, t_fdf **fdf);
void	print_map(t_fdf **fdf);
void	check_map(char *file, t_fdf **fdf);


/* Error messages*/
void	p_error(char *s);
#endif