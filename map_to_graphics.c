/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_graphics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:11:37 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/26 10:27:26 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_instr(char *av[])
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
	free(line);
	return (ft_split(map0, '\n'));
}

int	hook_f(int key, t_data *param)
{
	if (!param)
		exit(0);
	if (key == 53)
		exit(0);
	else if (key == 0)
		move_left(&param);
	else if (key == 2)
		move_right(&param);
	else if (key == 1)
		move_down(&param);
	else if (key == 13)
		move_up(&param);
	return (0);
}

int	c_nbr(char *map[])
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	hook_x(int key, t_data *param)
{
	if (param || key)
		exit(0);
	exit(0);
}

void	drawing(char *av[])
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->map = map_instr(av);
	data->count = c_nbr(data->map);
	if (data->count <= 0)
		errors(1);
	count_eandp(data->map);
	data->move_count = 0;
	data->l = 0;
	data->le = ft_strlen(data->map[0]);
	while (data->map[data->l])
		data->l++;
	data->mlx = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx, data->le * 50, data->l * 50, "2");
	if (!data->mlx || !data->win_ptr)
		exit(1);
	render(&data);
	mlx_hook(data->win_ptr, 17, 0, hook_x, data);
	mlx_hook(data->win_ptr, 2, 0, hook_f, data);
	mlx_loop(data->mlx);
	free_map(data->map);
	free(data);
}
