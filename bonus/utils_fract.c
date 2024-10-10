/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenjrai <bbenjrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:07:29 by bbenjrai          #+#    #+#             */
/*   Updated: 2024/05/18 22:31:15 by bbenjrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_img(t_mlx *mlx)
{
	mlx->image.img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->image.buffer = mlx_get_data_addr(mlx->image.img,
			&mlx->image.pixel_bits, &mlx->image.line_len, &mlx->image.endian);
}

int	calcule(int i, int it_max, t_complex comp)
{
	double	temp;
	double	image_fab;

	while (comp.z_real * comp.z_real + comp.z_imag * comp.z_imag < 4
		&& i < it_max)
	{
		temp = comp.z_real * comp.z_real - comp.z_imag * comp.z_imag
			+ comp.c_real;
		image_fab = 2 * comp.z_real * comp.z_imag + comp.c_imag;
		comp.z_imag = fabs(image_fab);
		comp.z_real = fabs(temp);
		i++;
	}
	return (i);
}

void	coloring_mand(int pos, int i, t_image image, int it_max)
{
	char	*p;

	p = (image.buffer + pos);
	if (i != it_max)
		*(unsigned int *)p = (i * 0xFFFFFF / it_max);
}
