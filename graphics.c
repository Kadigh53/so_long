/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:11:37 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/10 17:24:52 by aaoutem-         ###   ########.fr       */
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
	}
	close(fd);
	return (ft_split(map0,'\n'));
}

void	drawing(char *av[])
{
	void	*mlx;
	void	*win_ptr;
	void	*img;
	int		img_width;
	int		img_height;
	char	**map;
	int		x=0;
	int		y=0;
	int		l;
	int		Le;

	map = map_instr(av);
	l = 0;
	Le = ft_strlen(map[0]);
	while(map[l])
		l++;
	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx,Le*50,l*50,"KADIGH'S MAZ");
	
	while(x<Le) // && map[x]
	{
		// mlx_put_image_to_window(mlx, win_ptr,img,i*50,0);
		y = 0;
		while(y<l)
		{
			if (map[y][x] == '1')
			{
				img = mlx_xpm_file_to_image(mlx, "./cherjam_hmar.xpm", &img_width, &img_height);
				mlx_put_image_to_window(mlx, win_ptr,img,x*50,y*50);
			}
			else if (map[y][x] == 'C')
			{
				img = mlx_xpm_file_to_image(mlx, "./dollar_collectibles.xpm", &img_width, &img_height);
				mlx_put_image_to_window(mlx, win_ptr,img,x*50,y*50);
			}
			else if (map[y][x] == 'E')
			{
				img = mlx_xpm_file_to_image(mlx, "./bank_exit.xpm", &img_width, &img_height);
				mlx_put_image_to_window(mlx, win_ptr,img,x*50,y*50);
			}
			else if (map[y][x] == 'P')
			{
				img = mlx_xpm_file_to_image(mlx, "./MnP.xpm", &img_width, &img_height);
				mlx_put_image_to_window(mlx, win_ptr,img,x*50,y*50);
			}
			y++;
		}
		x++;
	}
	mlx_loop(mlx);
}

int main(int ac, char *av[])
{
	// char	**p=map_instr(av);
	// int i=0;
	// while(p[i])
	// 	i++;
	// printf("%d \n", i);
	drawing(av);
}