/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:54:57 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/07 21:02:12 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<mlx.h>
#include<stdio.h> 

// int	main()
// {
// 	void	*img;
// 	void	*mlx;

// 	mlx = mlx_init();
// 	img = mlx_new_window(mlx, 1920, 1080, "dyali achmn");
// 	mlx_loop(mlx);
// }
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0AA0);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 100);
	mlx_loop(mlx);
}