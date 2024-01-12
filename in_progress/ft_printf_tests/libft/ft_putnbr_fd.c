/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:27:03 by achappui          #+#    #+#             */
/*   Updated: 2023/11/01 10:29:01 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	process_ft_putnbr_fd(unsigned int us_n, int fd)
{
	if (us_n >= 10)
		process_ft_putnbr_fd(us_n / 10, fd);
	us_n = us_n % 10 + 48;
	write(fd, &us_n, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	us_n;

	if (n < 0)
	{
		write(fd, "-", 1);
		us_n = -n;
	}
	else
		us_n = n;
	process_ft_putnbr_fd(us_n, fd);
}
