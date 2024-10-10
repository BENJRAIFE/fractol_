/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenjrai <bbenjrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:05:31 by bbenjrai          #+#    #+#             */
/*   Updated: 2024/05/18 12:24:02 by bbenjrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_complex
{
	double		z_real;
	double		z_imag;
	double		c_real;
	double		c_imag;
}				t_complex;

typedef struct s_image
{
	char		*buffer;
	void		*img;
	int			pixel_bits;
	int			line_len;
	int			endian;
}				t_image;

typedef struct s_mlx
{
	int			width;
	int			height;
	void		*mlx;
	void		*mlx_win;
	double		zoom;
	int			it_max;
	int			x;
	int			y;
	int			ju_man;
	t_image		image;
	double		shifty;
	double		shiftx;
	t_complex	ccomp;
}				t_mlx;

int				calcule(int i, int it_max, t_complex comp);
void			create_img(t_mlx *mlx);
void			coloring_mand(int pos, int i, t_image image, int it_max);
int				mouse_hook(int key, int x, int y, t_mlx *vars);
void			closing(t_mlx *mlx);
void			calcule_mandel(t_mlx *mlx, t_complex comp);
void			calcule_julia(t_mlx *mlx, t_complex comp);
int				key_hook(int key, t_mlx *vars);
int				ft_close(t_mlx *vars);

// main funcs
void			mandel(void);
void			print_str(char *str);

#endif
