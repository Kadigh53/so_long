/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:22:17 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/26 03:58:35 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_insert(char *av[])
{
	char	*line;
	char	*map0;
	int		fd;

	fd = open(av[1], O_RDONLY);
	map0 = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map0 = ft_strjoin(map0, line);
		free(line);
	}
	close(fd);
	return (ft_split(map0, '\n'));
}

void	p_position(char **map, int *p_p)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				p_p[0] = i;
				p_p[1] = j;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char ***map, int y, int x)
{
	if ((*map)[y][x] == '1' || (*map)[y][x] == 'X')
		return ;
	(*map)[y][x] = 'X';
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
}

void	free_map(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	*backtrack(char **av)
{
	char	**map;
	int		p_p[2];
	int		i;
	int		j;

	i = 0;
	map = map_insert(av);
	p_position(map, p_p);
	flood_fill(&map, p_p[0], p_p[1]);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				free_map(map);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	free_map(map);
	return ((void *)1);
}
