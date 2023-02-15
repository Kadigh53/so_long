/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:43:20 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/15 22:43:29 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errors(int x)
{
	if (x == 0)
		write(2, "ERROR:invalid numbre of args\n./so_long map.ber",48);
	if (x == 1)
		write(2, "ERROR:invalid map",18);
}

int main(int ac, char *av[])
{
	char	*p;
	if (ac != 2)
		errors(0);
	if (!map_parsing(av))
		errors(1);
	drawing(av);
	// mlx_init();
}
