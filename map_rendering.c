/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:03:53 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/19 00:51:23 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    put_image(t_data **data, char *image_path)
{
	char	*str;

	(*data)->img = mlx_xpm_file_to_image((*data)->mlx, image_path,
											&(*data)->img_width,
											 &(*data)->img_height);
	if (!(*data)->img)
		exit(1);
	mlx_put_image_to_window((*data)->mlx, (*data)->win_ptr, (*data)->img,
							 (*data)->x * 50, (*data)->y * 50);
	str = ft_itoa((*data)->move_count);
	mlx_string_put((*data)->mlx,(*data)->win_ptr,20,13,0xFF00FF, str);
}

void render(t_data **data)
{
	(*data)->x = 0;
	while((*data)->x<(*data)->Le)
	{
		(*data)->y = 0;
		while((*data)->y<(*data)->l)
		{
			if ((*data)->map[(*data)->y][(*data)->x] == '1')
				put_image(data, "./images/cherjam_hmar.xpm");
			else if ((*data)->map[(*data)->y][(*data)->x] == 'C')
				put_image(data, "./images/dollar_collectibles.xpm");
			else if ((*data)->map[(*data)->y][(*data)->x] == 'E')
				put_image(data, "./images/bank_exit.xpm");
			else if ((*data)->map[(*data)->y][(*data)->x] == 'P')
			{
				(*data)->cor[0] = (*data)->y;
				(*data)->cor[1] = (*data)->x;
				put_image(data, "./images/MnP.xpm");
			}
			(*data)->y++;
		}
		(*data)->x++;
	}
}


// void render(t_data **data)
// {
//     int x;
//     int y;
    
// 	x = 0;
// 	while(x<(*data)->Le) 
// 	{
// 		y = 0;
// 		while(y<(*data)->l)
// 		{
// 			if ((*data)->map[y][x] == '1')
// 				put_image(data, "./cherjam_hmar.xpm");
// 			else if ((*data)->map[y][x] == 'C')
// 				put_image(data, "./dollar_collectibles.xpm");
// 			else if ((*data)->map[y][x] == 'E')
// 				put_image(data, "./bank_exit.xpm");
// 			else if ((*data)->map[y][x] == 'P')
// 			{
// 				(*data)->cor[0] = y;
// 				(*data)->cor[1] = x;
// 				put_image(data, "./MnP.xpm");
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// }