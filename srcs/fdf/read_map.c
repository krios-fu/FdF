/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:12:26 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/16 02:30:50 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	check_line_x(t_fdf **fdf, int wc)
{
	if ((*fdf)->map->x > 0 && (*fdf)->map->x != wc)
		p_error("Invalid map");
	else
		(*fdf)->map->x = wc;
}

void	allocate_map(t_fdf **fdf)
{
	int	i;

	i = 0;
	(*fdf)->map->table = (int **)malloc(sizeof(int *) * (*fdf)->map->y + 1);
	(*fdf)->map->color = (int **)malloc(sizeof(int *) * (*fdf)->map->y + 1);
	if (!(*fdf)->map->table || !(*fdf)->map->color)
		p_error("Fail malloc");
	while (i < (*fdf)->map->y)
	{
		(*fdf)->map->table[i] = (int *)malloc(sizeof(int) * (*fdf)->map->x + 1);
		(*fdf)->map->color[i] = (int *)malloc(sizeof(int) * (*fdf)->map->x + 1);
		if (!(*fdf)->map->table[i] || !(*fdf)->map->color[i])
			p_error("Fail malloc");
		i++;
	}
}

char	*str_ox(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == ',' || str[i] == '-' )
			i++;
		if (str[i] == ' ')
			return (NULL);
		if (str[i] == 'x')
			return (&str[i + 1]);
	}
	return (NULL);
}

void	fiil_map(char *file, t_fdf **fdf)
{
	t_aux_map	aux;

	aux.fd = open(file, O_RDONLY, 0);
	allocate_map(fdf);
	aux.y = 0;
	while (get_next_line(aux.fd, &aux.line) > 0)
	{
		aux.val = ft_split(aux.line, ' ');
		if (!aux.val)
			p_error("Fail malloc");
		aux.x = 0;
		while (aux.x < (*fdf)->map->x)
		{
			(*fdf)->map->table[aux.y][aux.x] = ft_atoi(aux.val[aux.x]);
			(*fdf)->map->color[aux.y][aux.x]
				= str_hexa_to_int(str_ox(aux.val[aux.x]));
			aux.x++;
		}
		aux.y++;
		free_matrix(aux.val);
		free(aux.line);
	}
	close(aux.fd);
	free(aux.line);
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
	while (get_next_line(fd, &line) > 0)
	{
		words = ft_split(line, ' ');
		check_line_x(fdf, word_count(words));
		(*fdf)->map->y++;
		free(line);
		free_matrix(words);
	}
	free(line);
	close(fd);
}
