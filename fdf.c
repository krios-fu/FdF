/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:03:59 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/12 02:58:55 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int main(void)
{
	t_fdf *fdf;
	t_map map;
	
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->map = &map;
	check_map("./test_maps/42.fdf", &fdf);
	fiil_map("./test_maps/42.fdf", &fdf);
	print_map(&fdf);
	return(0);
}