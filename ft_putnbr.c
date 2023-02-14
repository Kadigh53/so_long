/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:38:24 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/14 21:39:39 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	k;

	k = 1;
	if (n < 0)
	{
		k = n * (-1);
		write(fd, "-", 1);
	}
	else
		k = n;
	if (k < 10)
		ft_putchar_fd(k + '0', fd);
	else
	{
		ft_putnbr_fd(k / 10, fd);
		ft_putnbr_fd(k % 10, fd);
	}
}
