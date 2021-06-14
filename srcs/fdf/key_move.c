/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:01:57 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/14 19:07:00 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	key_move(t_fdf **fdf)
{
	if((*fdf)->cam->keycode->w == 1)
		(*fdf)->cam->dir_y -= 10;	
	if((*fdf)->cam->keycode->s == 1)
		(*fdf)->cam->dir_y += 10;
	if((*fdf)->cam->keycode->d == 1)
		(*fdf)->cam->dir_x += 10;
	if((*fdf)->cam->keycode->a == 1)
		(*fdf)->cam->dir_x -= 10;
	if((*fdf)->cam->keycode->zu == 1)
		(*fdf)->map->zoom += 1;
	if((*fdf)->cam->keycode->zd == 1)
		(*fdf)->map->zoom -= 1;
	if((*fdf)->cam->keycode->rr == 1)
		(*fdf)->cam->rotspeed -= 0.1;
	if((*fdf)->cam->keycode->rl == 1)
		(*fdf)->cam->rotspeed += 0.1;
	if((*fdf)->cam->keycode->p == 1)
		(*fdf)->cam->plane = 1;
	if((*fdf)->cam->keycode->i == 1)
		(*fdf)->cam->plane = 0;
	if((*fdf)->cam->keycode->q == 1)
		(*fdf)->cam->angle -= 0.1;
	if((*fdf)->cam->keycode->e == 1)
		(*fdf)->cam->angle += 0.1;
	return(0);
}