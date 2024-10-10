/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenjrai <bbenjrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:06:11 by bbenjrai          #+#    #+#             */
/*   Updated: 2024/05/23 15:46:11 by bbenjrai         ###   ########.fr       */
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
	(void)av;
	if (ac == 1)
	{
		mandel();
		return (0);
	}
	else
		print_str("Please Enter :\n./fractol_bonus\n");
}
