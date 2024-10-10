/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenjrai <bbenjrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:06:00 by bbenjrai          #+#    #+#             */
/*   Updated: 2024/05/18 22:47:13 by bbenjrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calcule_julia(t_mlx *mlx, t_complex comp)
{
	double	real;
	double	imag;
	int		i;

	create_img(mlx);
	mlx->y = 0;
	while (mlx->y < mlx->height)
	{
		mlx->x = 0;
		while (mlx->x < mlx->width)
		{
			i = 0;
			real = scaling(mlx, 1);
			imag = scaling(mlx, 2);
			comp.z_real = real;
			comp.z_imag = imag;
			i = calcule(i, mlx->it_max, comp);
			coloring_mand(position(mlx), i, mlx->image, mlx->it_max);
			mlx->x++;
		}
		mlx->y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->image.img, 0, 0);
}

void	julia(double cr, double ci)
{
	t_mlx		minilibix;
	t_complex	comp;

	minilibix.width = 800;
	minilibix.height = 860;
	minilibix.it_max = 200;
	minilibix.mlx = mlx_init();
	minilibix.mlx_win = mlx_new_window(minilibix.mlx, minilibix.width,
			minilibix.height, "fractol");
	comp.c_real = cr;
	comp.c_imag = ci;
	minilibix.ccomp = comp;
	minilibix.zoom = 1;
	minilibix.shiftx = 0;
	minilibix.shifty = 0;
	minilibix.ju_man = 2;
	calcule_julia(&minilibix, comp);
	mlx_mouse_hook(minilibix.mlx_win, mouse_hook, &minilibix);
	mlx_key_hook(minilibix.mlx_win, key_hook, &minilibix);
	mlx_hook(minilibix.mlx_win, 17, 0, ft_close, &minilibix);
	mlx_loop(minilibix.mlx);
}
