/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:12:48 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/11 21:55:12 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_
# define FDF_
# include "../srcs/libft/libft.h"
# include "../srcs/gnl/get_next_line_bonus.h"

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

int word_count(char **str);


/* Error messages*/
void	p_error(char *s);
#endif