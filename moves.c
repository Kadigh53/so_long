/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:46:53 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/16 18:42:20 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data **data)
{
	if (((*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] == '1' || 
		(*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] == 'E') && (*data)->Count)
		return;
	else if ((*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] == 'E' && (*data)->Count == 0)
		exit(0);
	else
	{
        if ((*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] == 'C')
            (*data)->Count--;
		(*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] = 'P';
		(*data)->map[(*data)->cor[0]][(*data)->cor[1]] = '0';
		(*data)->cor[1] -= 1;
	}
	mlx_clear_window((*data)->mlx,(*data)->win_ptr);
	render(data);
}

void	move_right(t_data **data)
{
	if (((*data)->map[(*data)->cor[0]][(*data)->cor[1] + 1] == '1' || 
		(*data)->map[(*data)->cor[0]][(*data)->cor[1] + 1] == 'E') && (*data)->Count)
		return;
	else if ((*data)->map[(*data)->cor[0]][(*data)->cor[1] + 1] == 'E' && (*data)->Count == 0)
		exit(0);
	else
	{
        if ((*data)->map[(*data)->cor[0]][(*data)->cor[1] + 1] == 'C')
			(*data)->Count--;
		(*data)->map[(*data)->cor[0]][(*data)->cor[1] + 1] = 'P';
		(*data)->map[(*data)->cor[0]][(*data)->cor[1]] = '0';
		(*data)->cor[1] += 1;
	}
	mlx_clear_window((*data)->mlx,(*data)->win_ptr);
	render(data);
}

void	move_up(t_data **data)
{
	if (((*data)->map[(*data)->cor[0] - 1][(*data)->cor[1]] == '1' || 
		(*data)->map[(*data)->cor[0] - 1][(*data)->cor[1]] == 'E') && (*data)->Count)
		return;
	else if ((*data)->map[(*data)->cor[0] - 1][(*data)->cor[1]] == 'E' && (*data)->Count == 0)
		exit(0);
	else
	{
        if ((*data)->map[(*data)->cor[0] - 1][(*data)->cor[1]] == 'C')
            (*data)->Count--;
		(*data)->map[(*data)->cor[0] - 1][(*data)->cor[1]] = 'P';
		(*data)->map[(*data)->cor[0]][(*data)->cor[1]] = '0';
		(*data)->cor[0] -= 1;
	}
	mlx_clear_window((*data)->mlx,(*data)->win_ptr);
	render(data);
}

void	move_down(t_data **data)
{
	if (((*data)->map[(*data)->cor[0] + 1][(*data)->cor[1]] == '1' || 
		(*data)->map[(*data)->cor[0] + 1][(*data)->cor[1]] == 'E' ) && (*data)->Count)
		return;
	else if ((*data)->map[(*data)->cor[0] + 1][(*data)->cor[1]] == 'E' && (*data)->Count == 0)
		exit(0);
	else 
	{
        if ((*data)->map[(*data)->cor[0] + 1][(*data)->cor[1]] == 'C')
		    (*data)->Count--;
		(*data)->map[(*data)->cor[0] + 1][(*data)->cor[1]] = 'P';
		(*data)->map[(*data)->cor[0]][(*data)->cor[1]] = '0';
		(*data)->cor[0] += 1;
	}
	mlx_clear_window((*data)->mlx,(*data)->win_ptr);
	render(data);
}
