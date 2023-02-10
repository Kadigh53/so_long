/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:43:20 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/08 22:51:17 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*win_ptr;
	void	*img;
	char	*relative_path = "./cherjam_hmar.xpm";
	// char	*relative_path = "./btc50.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx,1050,550,"KADIGH'S MAZ");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	// mlx_put_image_to_window(mlx, win_ptr,img,50,50);
	int i=0;
	while(i<21)
	{
		mlx_put_image_to_window(mlx, win_ptr,img,i*50,0);
		mlx_put_image_to_window(mlx, win_ptr,img,i*50,500);
		i++;
	}
	i=1;
	// while(i<10)
	// {
	// 	mlx_put_image_to_window(mlx, win_ptr,img,0,i*50);
	// 	mlx_put_image_to_window(mlx, win_ptr,img,1000,i*50);
	// 	i++;
	// }
	mlx_loop(mlx);
}