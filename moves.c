/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:46:53 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/15 18:53:12 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data **data)
{
	int i =0;
	while((*data)->map[i])
	{
		ft_putstr_fd((*data)->map[i],1);
		write(1,"\n",1);
		i++;
	}
	if ((*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] == '1' || 
		(*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] == 'E')
		return;
	else //if ((*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] == 'C')
	{
		(*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] = 'P';
		(*data)->map[(*data)->cor[0]][(*data)->cor[1]] = '0';
		(*data)->cor[1] -= 1;
	}
	mlx_clear_window((*data)->mlx,(*data)->win_ptr);
	render(data);
}