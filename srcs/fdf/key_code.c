/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 15:29:57 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/14 02:55:36 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_keypress(int key, t_fdf **fdf)
{
	//write(2, ft_itoa(key), 3);
	if (key == KEY_UP && ((*fdf)->cam->keycode->w == 0))
		(*fdf)->cam->keycode->w  = 1;
	if (key == KEY_DOWN && ((*fdf)->cam->keycode->s == 0))
		(*fdf)->cam->keycode->s  = 1;
	if (key == KEY_RIGHT && ((*fdf)->cam->keycode->d == 0))
		(*fdf)->cam->keycode->d = 1;
	if (key == KEY_LEFT && ((*fdf)->cam->keycode->a == 0))
		(*fdf)->cam->keycode->a = 1;
	if (key == KEY_UP_ZOOM && ((*fdf)->cam->keycode->zu == 0))
		(*fdf)->cam->keycode->zu = 1;
	if (key == KEY_DOWM_ZOOM && ((*fdf)->cam->keycode->zd == 0))
		(*fdf)->cam->keycode->zd = 1;
	if (key == KEY_RIGHT_VISION && ((*fdf)->cam->keycode->rr == 0))
		(*fdf)->cam->keycode->rr = 1;
	if (key == KEY_LEFT_VISION && ((*fdf)->cam->keycode->rl == 0))
		(*fdf)->cam->keycode->rl = 1;
	if (key == KEY_PLANE_VISION && ((*fdf)->cam->keycode->p == 0))
		(*fdf)->cam->keycode->p = 1;
	if (key == KEY_ISO_VISION && ((*fdf)->cam->keycode->i == 0))
		(*fdf)->cam->keycode->i = 1;
	start(fdf);
	
	return (0);
}

int	ft_keyrelease(int key, t_fdf **fdf)
{
	if (key == KEY_UP && ((*fdf)->cam->keycode->w == 1))
		(*fdf)->cam->keycode->w = 0;
	if (key == KEY_DOWN && ((*fdf)->cam->keycode->s == 1))
		(*fdf)->cam->keycode->s = 0;
	if (key == KEY_RIGHT && ((*fdf)->cam->keycode->d == 1))
		(*fdf)->cam->keycode->d = 0;
	if (key == KEY_LEFT && ((*fdf)->cam->keycode->a == 1))
		(*fdf)->cam->keycode->a = 0;
	if (key == KEY_UP_ZOOM && ((*fdf)->cam->keycode->zu == 1))
		(*fdf)->cam->keycode->zu = 0;
	if (key == KEY_DOWM_ZOOM && ((*fdf)->cam->keycode->zd == 1))
		(*fdf)->cam->keycode->zd = 0;
	if (key == KEY_RIGHT_VISION && ((*fdf)->cam->keycode->rr == 1))
		(*fdf)->cam->keycode->rr = 0;
	if (key == KEY_LEFT_VISION && ((*fdf)->cam->keycode->rl == 1))
		(*fdf)->cam->keycode->rl = 0;
	if (key == KEY_PLANE_VISION && ((*fdf)->cam->keycode->p == 1))
		(*fdf)->cam->keycode->p = 0;
	if (key == KEY_ISO_VISION && ((*fdf)->cam->keycode->i == 1))
		(*fdf)->cam->keycode->i = 0;
	return (0);
}
