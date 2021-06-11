/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:12:26 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/11 23:05:36 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_line_x(t_fdf **fdf, int wc)
{
	if((*fdf)->map->x > 0 && (*fdf)->map->x != wc)
		p_error("Invalid map");
	else 
		(*fdf)->map->x = wc;	
}

void	allocate_map(t_fdf **fdf)
{
	int		i;
	
	i = 0;
	(*fdf)->map->table = (int **)malloc(sizeof(int *) * (*fdf)->map->x);
	if(!(*fdf)->map->table)
		p_error("Fail malloc");
	while (i < (*fdf)->map->x)
	{
		(*fdf)->map->table[i] = (int *)malloc(sizeof(int) * (*fdf)->map->y);
		if(!(*fdf)->map->table[i])
			p_error("Fail malloc");
		i++;
	}
}
void	fiil_map(char *file, t_fdf **fdf)
{
	char	*line;
	char	**val;
	int		fd;
	int		x;
	int		y;

	fd = open(file, O_RDONLY);
	allocate_map(fdf);
	x = 0;
	y = 0;
	while(get_next_line(fd, &line) > 0)
	{
		//printf("\n");
		val = ft_split(line, ' ');
		printf("%s  ", val[0]);
		if(!val)
			p_error("Fail malloc");
		while(y < (*fdf)->map->y)
		{
			x = 0;
			while ( x < (*fdf)->map->x)
			{
				// (*fdf)->map->table[y][x] = (int)ft_atoi((char *)val[x]);
				x++;
			}
			//free(val[y]);
			printf("\n");
			y++;
		}
		free(line);
	}
	//free(val);
	free(line);
}

void print_map(t_fdf **fdf)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while(y < (*fdf)->map->y)
	{
		x = 0;
		while ( x < (*fdf)->map->x)
		{
			printf("%d  ", (*fdf)->map->table[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	check_map(char *file, t_fdf **fdf)
{
	char	*line;
	char	**words;
	int		fd;

	words = NULL;
	fd = open(file, O_RDONLY);
	(*fdf)->map->y = 0;
	(*fdf)->map->x = 0;
	while(get_next_line(fd, &line) > 0)
	{
		words = ft_split(line, ' ');
		check_line_x(fdf, word_count(words));
		(*fdf)->map->y++;
		free(line);
	}
	free(line);
	close(fd);
}

int main()
{
	t_fdf *fdf;
	t_map map;
	
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->map = &map;
	check_map("../test_maps/42.fdf", &fdf);
	fiil_map("../test_maps/42.fdf", &fdf);
	print_map(&fdf);
}