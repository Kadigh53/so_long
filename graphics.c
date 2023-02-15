/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:11:37 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/15 19:07:31 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include<mlx.h>
// #include "get_next_line.h"

char	**map_instr(char *av[])
{
	char	*line;
	char	*map0;
	int		fd;

	fd = open(av[1],O_RDONLY);
	map0=NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map0 = ft_strjoin(map0, line);
		free(line);
	}
	close(fd);
	return (ft_split(map0,'\n'));
}

// void	move_left(t_data **data)
// {
// 	int i =0;
// 	while((*data)->map[i])
// 	{
// 		ft_putstr_fd((*data)->map[i],1);
// 		write(1,"\n",1);
// 		i++;
// 	}
// 	if ((*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] == '1' || 
// 		(*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] == 'E')
// 		return;
// 	else //if ((*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] == 'C')
// 	{
// 		(*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] = 'P';
// 		(*data)->map[(*data)->cor[0]][(*data)->cor[1]] = '0';
// 		(*data)->cor[1] -= 1;
// 	}
// 	mlx_clear_window((*data)->mlx,(*data)->win_ptr);
// 	render(data);
// }

int	hook_f(int key, t_data *param)
{
	if (!key && !param)
		exit(0);
	ft_putnbr_fd(key, 1);
	write(1, "\n", 1);
	if (key == 53)
		exit(0);
	if (key == 0)
		move_left(&param);
	if (key == 2)
		move_right(&param);
	if (key == 1)
		move_down(&param);
	if (key == 13)
		move_up(&param);
	return 0;
}

void	drawing(char *av[])
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	// data->x = 0;
	// data->y = 0;
	data->map = map_instr(av);
	data->l = 0;
	data->Le = ft_strlen(data->map[0]);
	while(data->map[data->l])
		data->l++;
	data->mlx = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx,data->Le*50,data->l*50, "WINDW");
	render(&data);
	// mlx_hookdata->win_ptr, 17, 0, hook_f, NULL);
	// ft_putstr_fd();
	mlx_hook(data->win_ptr, 2, 0, hook_f, data);
	mlx_loop(data->mlx);
}

int main(int ac, char *av[])
{
	drawing(av);
}



// typedef structdata 
// {
// 	void	*mlx;
// 	void	*win_ptr;
// 	void	*img;
// 	int		img_width;
// 	int		img_height;
// 	char	**map;
// 	int		x;
// 	int		y;
// 	int		l;
// 	int		Le;
// } t_data;