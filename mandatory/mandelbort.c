/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenjrai <bbenjrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:06:24 by bbenjrai          #+#    #+#             */
/*   Updated: 2024/05/23 15:44:55 by bbenjrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int	position(t_mlx *mlx)
{
	int	pos;

	pos = (mlx->y * mlx->image.line_len) + (mlx->x * (mlx->image.pixel_bits
				/ 8));
	return (pos);
}

double	scaling(t_mlx *mlx, int x_y)
{
	double	scale;

	scale = 0.0;
	if (x_y == 1)
	{
		scale = ((mlx->x - mlx->width / 2.0) * 4.0 / mlx->width * mlx->zoom)
			+ mlx->shiftx;
	}
	else if (x_y == 2)
	{
		scale = ((mlx->y - mlx->height / 2.0) * 4.0 / mlx->height * mlx->zoom)
			+ mlx->shifty;
	}
	return (scale);
}

void	initiale(t_complex *comp, double real, double imag)
{
	comp->c_real = real;
	comp->c_imag = imag;
	comp->z_real = 0;
	comp->z_imag = 0;
}

void	calcule_mandel(t_mlx *mlx, t_complex comp)
{
	double	real;
	double	imag;
	int		i;
	int		pos;

	create_img(mlx);
	mlx->y = 0;
	while (mlx->y < mlx->height)
	{
		mlx->x = 0;
		while (mlx->x < mlx->width)
		{
			i = 0;
			pos = 0;
			real = scaling(mlx, 1);
			imag = scaling(mlx, 2);
			initiale(&comp, real, imag);
			i = calcule(i, mlx->it_max, comp);
			pos = position(mlx);
			coloring_mand(pos, i, mlx->image, mlx->it_max);
			mlx->x++;
		}
		mlx->y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->image.img, 0, 0);
}

void	mandel(void)
{
	t_mlx		minilibix;
	t_complex	comp;

	comp.z_imag = 0;
	comp.z_real = 0;
	minilibix.width = 800;
	minilibix.height = 900;
	minilibix.it_max = 200;
	minilibix.mlx = mlx_init();
	minilibix.mlx_win = mlx_new_window(minilibix.mlx, minilibix.width,
			minilibix.height, "fractol");
	minilibix.zoom = 1;
	minilibix.shiftx = 0;
	minilibix.shifty = 0;
	minilibix.ju_man = 1;
	calcule_mandel(&minilibix, comp);
	mlx_mouse_hook(minilibix.mlx_win, mouse_hook, &minilibix);
	mlx_key_hook(minilibix.mlx_win, key_hook, &minilibix);
	mlx_hook(minilibix.mlx_win, 17, 0, ft_close, &minilibix);
	mlx_loop(minilibix.mlx);
}
