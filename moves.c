/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:46:53 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/26 08:50:26 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data **data)
{
	if (((*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] == '1'
		|| (*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] == 'E')
		&& (*data)->count)
		return ;
	else if ((*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] == 'E'
			&& (*data)->count == 0)
		exit(0);
	else if ((*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] == '0'
			|| (*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] == 'C')
	{
		if ((*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] == 'C')
			(*data)->count--;
		(*data)->map[(*data)->cor[0]][(*data)->cor[1] - 1] = 'P';
		(*data)->map[(*data)->cor[0]][(*data)->cor[1]] = '0';
		(*data)->cor[1] -= 1;
		(*data)->move_count++;
		ft_putnbr_fd((*data)->move_count, 1);
		write(1, "\n", 1);
	}
	mlx_clear_window((*data)->mlx, (*data)->win_ptr);
	render(data);
}

void	move_right(t_data **data)
{
	if (((*data)->map[(*data)->cor[0]][(*data)->cor[1] + 1] == '1'
		|| (*data)->map[(*data)->cor[0]][(*data)->cor[1] + 1] == 'E')
		&& (*data)->count)
		return ;
	else if ((*data)->map[(*data)->cor[0]][(*data)->cor[1] + 1] == 'E'
			&& (*data)->count == 0)
		exit(0);
	else if ((*data)->map[(*data)->cor[0]][(*data)->cor[1] + 1] == '0'
			|| (*data)->map[(*data)->cor[0]][(*data)->cor[1] + 1] == 'C')
	{
		if ((*data)->map[(*data)->cor[0]][(*data)->cor[1] + 1] == 'C')
			(*data)->count--;
		(*data)->map[(*data)->cor[0]][(*data)->cor[1] + 1] = 'P';
		(*data)->map[(*data)->cor[0]][(*data)->cor[1]] = '0';
		(*data)->cor[1] += 1;
		(*data)->move_count++;
		ft_putnbr_fd((*data)->move_count, 1);
		write(1, "\n", 1);
	}
	mlx_clear_window((*data)->mlx, (*data)->win_ptr);
	render(data);
}

void	move_up(t_data **data)
{
	if (((*data)->map[(*data)->cor[0] - 1][(*data)->cor[1]] == '1'
		|| (*data)->map[(*data)->cor[0] - 1][(*data)->cor[1]] == 'E')
		&& (*data)->count)
		return ;
	else if ((*data)->map[(*data)->cor[0] - 1][(*data)->cor[1]] == 'E'
			&& (*data)->count == 0)
		exit(0);
	else if ((*data)->map[(*data)->cor[0] - 1][(*data)->cor[1]] == '0'
			|| (*data)->map[(*data)->cor[0] - 1][(*data)->cor[1]] == 'C')
	{
		if ((*data)->map[(*data)->cor[0] - 1][(*data)->cor[1]] == 'C')
			(*data)->count--;
		(*data)->map[(*data)->cor[0] - 1][(*data)->cor[1]] = 'P';
		(*data)->map[(*data)->cor[0]][(*data)->cor[1]] = '0';
		(*data)->cor[0] -= 1;
		(*data)->move_count++;
		ft_putnbr_fd((*data)->move_count, 1);
		write(1, "\n", 1);
	}
	mlx_clear_window((*data)->mlx, (*data)->win_ptr);
	render(data);
}

void	move_down(t_data **data)
{
	if (((*data)->map[(*data)->cor[0] + 1][(*data)->cor[1]] == '1'
		|| (*data)->map[(*data)->cor[0] + 1][(*data)->cor[1]] == 'E' )
		&& (*data)->count)
		return ;
	else if ((*data)->map[(*data)->cor[0] + 1][(*data)->cor[1]] == 'E'
			&& (*data)->count == 0)
		exit(0);
	else if ((*data)->map[(*data)->cor[0] + 1][(*data)->cor[1]] == '0'
			|| (*data)->map[(*data)->cor[0] + 1][(*data)->cor[1]] == 'C')
	{
		if ((*data)->map[(*data)->cor[0] + 1][(*data)->cor[1]] == 'C')
			(*data)->count--;
		(*data)->map[(*data)->cor[0] + 1][(*data)->cor[1]] = 'P';
		(*data)->map[(*data)->cor[0]][(*data)->cor[1]] = '0';
		(*data)->cor[0] += 1;
		(*data)->move_count++;
		ft_putnbr_fd((*data)->move_count, 1);
		write(1, "\n", 1);
	}
	mlx_clear_window((*data)->mlx, (*data)->win_ptr);
	render(data);
}
