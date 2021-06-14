/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:12:26 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/14 23:02:35 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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
	(*fdf)->map->table = (int **)malloc(sizeof(int *) * (*fdf)->map->y + 1);
	(*fdf)->map->color = (int **)malloc(sizeof(int *) * (*fdf)->map->y + 1);
	if(!(*fdf)->map->table || !(*fdf)->map->color)
		p_error("Fail malloc");
	while (i < (*fdf)->map->y)
	{
		(*fdf)->map->table[i] = (int *)malloc(sizeof(int) * (*fdf)->map->x + 1);
		(*fdf)->map->color[i] = (int *)malloc(sizeof(int) * (*fdf)->map->x + 1);
		if(!(*fdf)->map->table[i] || !(*fdf)->map->table[i])
			p_error("Fail malloc");
		i++;
	}
	
}
void	fiil_map(char *file, t_fdf **fdf)
{
	t_aux_map aux;

	aux.fd = open(file, O_RDONLY, 0);
	allocate_map(fdf);
	aux.y = 0;
	while(get_next_line(aux.fd, &aux.line) > 0)
	{
		aux.val = ft_split(aux.line, ' ');
		if(!aux.val)
			p_error("Fail malloc");
		aux.x = 0;
		while ( aux.x < (*fdf)->map->x)
		{
			(*fdf)->map->table[aux.y][aux.x] = ft_atoi(aux.val[aux.x]);
			aux.x++;
			free(aux.val[aux.x]);
		}
		(*fdf)->map->table[aux.y][aux.x] = 0;
		aux.y++;
		free(aux.val);
		free(aux.line);
	}
	(*fdf)->map->table[aux.y] = 0;
	free(aux.line);
}


int			ft_rgb(int r, int g, int b)
{
	int rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}


int str_hexa_to_int(char *str)
{
	int num;
	int i;

	i = 2;
	write(2, "entre COLOR\n", 13);
	while (str[i])
	{
		if(str[i] >= '0' && str[i] <= '9')
	   		num = num * 16 + str[i] - '0';
	  	if(str[i] >= 'a' && str[i] <= 'f')
	   		num = num * 16 + str[i] - 'a' + 10;
	  	if(str[i] >= 'A' && str[i] <= 'F')
	  	 num = num * 16 + str[i] - 'A'+ 10; 
		i++;
	}
	return (num);
}

void	get_color(char *file, t_fdf **fdf)
{
	t_aux_map aux;

	aux.fd = open(file, O_RDONLY, 0);
	allocate_map(fdf);
	aux.y = 0;
	while(get_next_line(aux.fd, &aux.line) > 0)
	{
		aux.val = ft_split(aux.line, ' ');
		if(!aux.val)
			p_error("Fail malloc");
		aux.x = 0;
		while ( aux.x < (*fdf)->map->x)
		{
			write(2, "entre X\n", 9);
			aux.color = ft_split(&aux.val[aux.y][aux.x], ',');
			if (aux.color[1])
			{
				(*fdf)->map->color[aux.y][aux.x] = str_hexa_to_int(aux.color[1]);
				free(aux.color[1]);
			}
			else
				(*fdf)->map->color[aux.y][aux.x] = 0XFFFFFF;
			aux.x++;
			free(aux.val[aux.x]);
			free(aux.color[0]);
			free(aux.color);
		}
		(*fdf)->map->table[aux.y][aux.x] = 0;
		aux.y++;
		free(aux.val);
		free(aux.line);
	}
	(*fdf)->map->table[aux.y] = 0;
	free(aux.line);
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
			printf("%3d", (*fdf)->map->table[y][x]);
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
