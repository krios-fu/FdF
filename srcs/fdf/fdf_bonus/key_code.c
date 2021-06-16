/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 15:29:57 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/16 20:59:26 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void static	ft_keypress_two(int key, t_fdf **fdf)
{
	if (key == KEY_LEFT_VISION && ((*fdf)->cam->keycode->rl == 0))
		(*fdf)->cam->keycode->rl = 1;
	if (key == KEY_PLANE_VISION && ((*fdf)->cam->keycode->p == 0))
		(*fdf)->cam->keycode->p = 1;
	if (key == KEY_ISO_VISION && ((*fdf)->cam->keycode->i == 0))
		(*fdf)->cam->keycode->i = 1;
	if (key == KEY_ANGLE_E_VISION && ((*fdf)->cam->keycode->e == 0))
		(*fdf)->cam->keycode->e = 1;
	if (key == KEY_ANGLE_Q_VISION && ((*fdf)->cam->keycode->q == 0))
		(*fdf)->cam->keycode->q = 1;
	if (key == KEY_ELE_C_VISION && ((*fdf)->cam->keycode->c == 0))
		(*fdf)->cam->keycode->c = 1;
	if (key == KEY_ELE_X_VISION && ((*fdf)->cam->keycode->x == 0))
		(*fdf)->cam->keycode->x = 1;
	if (key == ESC && (*fdf)->cam->keycode->esc == 0)
		(*fdf)->cam->keycode->esc = 1;
	if (key == KEY_SCREEN_SHOT)
		ft_screenshot(fdf);
	if (key == KEY_UNIVER_VISION)
	{
		if (!(*fdf)->cam->keycode->sp)
			(*fdf)->cam->keycode->sp = 1;
		else
			(*fdf)->cam->keycode->sp = 0;
	}
}

int	ft_keypress(int key, t_fdf **fdf)
{
	if (key == KEY_UP && ((*fdf)->cam->keycode->w == 0))
		(*fdf)->cam->keycode->w = 1;
	if (key == KEY_DOWN && ((*fdf)->cam->keycode->s == 0))
		(*fdf)->cam->keycode->s = 1;
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
	ft_keypress_two(key, fdf);
	start(fdf);
	return (0);
}

void static	ft_keyrelease_two(int key, t_fdf **fdf)
{
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
	if (key == KEY_ANGLE_E_VISION && ((*fdf)->cam->keycode->e == 1))
		(*fdf)->cam->keycode->e = 0;
	if (key == KEY_ANGLE_Q_VISION && ((*fdf)->cam->keycode->q == 1))
		(*fdf)->cam->keycode->q = 0;
	if (key == KEY_ELE_C_VISION && ((*fdf)->cam->keycode->c == 1))
		(*fdf)->cam->keycode->c = 0;
	if (key == KEY_ELE_X_VISION && ((*fdf)->cam->keycode->x == 1))
		(*fdf)->cam->keycode->x = 0;
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
	ft_keyrelease_two(key, fdf);
	return (0);
}
