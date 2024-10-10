/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenjrai <bbenjrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:06:52 by bbenjrai          #+#    #+#             */
/*   Updated: 2024/05/23 21:12:43 by bbenjrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < len)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_isdigit(int c)
{
	if (c != '\0')
	{
		if ((c <= '9' && c >= '0'))
			return (1);
		else
			return (0);
	}
	return (0);
}

int	is_valid(char *av)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while ((av[i] >= 9 && av[i] <= 13) || av[i] == 32)
		i++;
	if (av[i] == '+' || av[i] == '-')
		av++;
	if (av[i] == '\0')
		return (0);
	while (av[i] && (ft_isdigit(av[i]) || (av[i] == '.' && av[i + 1])))
	{
		if (av[i] == '.')
			f++;
		if (f == 2)
			return (0);
		i++;
	}
	while ((av[i] >= 9 && av[i] <= 13) || av[i] == 32)
		i++;
	return (ft_strlen(av) == i && i != 0);
}

double	ft_todouble(char *str, int i)
{
	double	resd;
	int		j;

	j = 1;
	resd = 0.0;
	while ((str[i] <= '9' && str[i] >= '0') || str[i] == '.')
	{
		if (str[i] == '.')
			i++;
		while (ft_isdigit((unsigned char)str[i]))
			resd += (str[i++] - '0') / pow(10, j++);
	}
	return (resd);
}

double	ft_atod(char *str)
{
	int		i;
	int		sign;
	int		resi;
	double	resd;

	i = 0;
	sign = 1;
	resi = 0;
	resd = 0.0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -sign;
	}
	while (str[i] <= '9' && str[i] >= '0')
		resi = resi * 10 + str[i++] - '0';
	resd = ft_todouble(str, i);
	return (resd + resi * sign);
}
