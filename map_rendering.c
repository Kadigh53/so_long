/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:03:53 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/26 05:09:52 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data **data, char *image_path)
{
	(*data)->img = mlx_xpm_file_to_image((*data)->mlx, image_path,
			&(*data)->img_width, &(*data)->img_height);
	if (!(*data)->img)
		exit(1);
	mlx_put_image_to_window((*data)->mlx, (*data)->win_ptr, (*data)->img,
		(*data)->x * 50, (*data)->y * 50);
}

void	render(t_data **data)
{
	(*data)->x = 0;
	while ((*data)->x < (*data)->le)
	{
		(*data)->y = 0;
		while ((*data)->y < (*data)->l)
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
