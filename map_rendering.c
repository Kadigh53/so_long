/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:03:53 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/14 23:22:43 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    put_image(t_data **data, char *image_path)
{
	(*data)->img = mlx_xpm_file_to_image((*data)->mlx, image_path,
											&(*data)->img_width,
											 &(*data)->img_height);
	mlx_put_image_to_window((*data)->mlx, (*data)->win_ptr, (*data)->img,
							 (*data)->x * 50, (*data)->y * 50);
}

void render(t_data **data)
{
	while((*data)->x<(*data)->Le) // && map[x]
	{
		(*data)->y = 0;
		while((*data)->y<(*data)->l)
		{
			if ((*data)->map[(*data)->y][(*data)->x] == '1')
				put_image(data, "./cherjam_hmar.xpm");
			else if ((*data)->map[(*data)->y][(*data)->x] == 'C')
				put_image(data, "./dollar_collectibles.xpm");
			else if ((*data)->map[(*data)->y][(*data)->x] == 'E')
				put_image(data, "./bank_exit.xpm");
			else if ((*data)->map[(*data)->y][(*data)->x] == 'P')
				put_image(data, "./MnP.xpm");
			(*data)->y++;
		}
		(*data)->x++;
	}
}
