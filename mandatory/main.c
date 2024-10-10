/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenjrai <bbenjrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:06:11 by bbenjrai          #+#    #+#             */
/*   Updated: 2024/05/23 21:27:28 by bbenjrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_strlower(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] <= 'Z' && av[i] >= 'A')
			av[i] += 32;
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_strlower(av[1]);
		if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot", 10)))
		{
			mandel();
		}
		else if (ac == 4 && !ft_strcmp(av[1], "julia", 5) && is_valid(av[2])
			&& is_valid(av[3]))
		{
			julia(ft_atod(av[2]), ft_atod(av[3]));
		}
		else
		{
			print_str("Please Enter:\n./fractol mandelbrot OR julia <x> <y>\n");
			exit(1);
		}
	}
	else
	{
		print_str("Please Enter:\n./fractol mandelbrot OR julia <x> <y>\n");
		exit(1);
	}
}
