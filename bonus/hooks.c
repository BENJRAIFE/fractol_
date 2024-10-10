/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenjrai <bbenjrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:05:47 by bbenjrai          #+#    #+#             */
/*   Updated: 2024/05/18 21:04:45 by bbenjrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	closing(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->image.img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
}

int	ft_close(t_mlx *vars)
{
	closing(vars);
	return (0);
}

int	key_hook(int keycode, t_mlx *win)
{
	if (keycode == 65362)
		win->shifty -= 0.5 * win->zoom;
	else if (keycode == 65364)
		win->shifty += 0.5 * win->zoom;
	else if (keycode == 65361)
		win->shiftx -= 0.5 * win->zoom;
	else if (keycode == 65363)
		win->shiftx += 0.5 * win->zoom;
	else if (keycode == 65451)
		win->it_max += 10;
	else if (keycode == 65453 && win->it_max - 10 > 5)
		win->it_max -= 10;
	else if (keycode == 'q' || keycode == 'Q' || keycode == 65307)
		closing(win);
	mlx_destroy_image(win->mlx, win->image.img);
	calcule_mandel(win, win->ccomp);
	return (0);
}

int	mouse_hook(int key, int x, int y, t_mlx *vars)
{
	double	real;
	double	imag;
	double	oreal;
	double	oimag;

	oreal = ((x - vars->width / 2.0) * 4.0 / vars->width * vars->zoom)
		+ vars->shiftx;
	oimag = ((y - vars->height / 2.0) * 4.0 / vars->height * vars->zoom)
		+ vars->shifty;
	if (key == 4)
		vars->zoom *= 1.15;
	else if (key == 5)
		vars->zoom *= 0.85;
	real = ((x - vars->width / 2.0) * 4.0 / vars->width * vars->zoom)
		+ vars->shiftx;
	imag = ((y - vars->height / 2.0) * 4.0 / vars->height * vars->zoom)
		+ vars->shifty;
	vars->shiftx += oreal - real;
	vars->shifty += oimag - imag;
	mlx_destroy_image(vars->mlx, vars->image.img);
	calcule_mandel(vars, vars->ccomp);
	return (0);
}
