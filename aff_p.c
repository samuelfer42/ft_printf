/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:32:05 by safernan          #+#    #+#             */
/*   Updated: 2020/01/18 15:35:43 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_blank(int nb)
{
	int		i;
	char	c;

	c = ' ';
	i = 0;
	while (i < nb)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

static int	ft_size(unsigned long nb)
{
	int				i;
	long long		x;

	x = 1;
	i = 1;
	while (nb / x > 15)
	{
		x = 16 * x;
		i++;
	}
	return (i + 2);
}

static int	ft_shift(char **line)
{
	int		i;

	i = 0;
	while ((*line)[i])
		i++;
	(*line)[i + 1] = 0;
	while (i > 0)
	{
		(*line)[i] = (*line)[i - 1];
		i--;
	}
	return (1);
}

static int	ft_put(unsigned long nb, char **line)
{
	int		len;
	int		ret;

	len = ft_size(nb);
	if (!(*line = malloc(len + 1)))
		return (-1);
	ret = ft_itoa_base("0123456789abcdef", nb, line);
	ft_shift(line);
	ft_shift(line);
	(*line)[0] = '0';
	(*line)[1] = 'x';
	return (len);
}

int			aff_p(t_arg *arg, va_list ap)
{
	unsigned long	nb;
	char			*line;
	int				ret;
	int				sp;

	if (arg->s_longueur == 1)
		arg->longueur = va_arg(ap, int);
	nb = (unsigned long)va_arg(ap, void *);
	if (arg->precision == 1 || arg->zero == 1)
		return (-1);
	if ((ret = ft_put(nb, &line)) == -1)
		return (-1);
	if (arg->moins)
	{
		write(1, line, ret);
		free(line);
		return (ret + ft_blank(arg->largeur_min - ret));
	}
	sp = ft_blank(arg->largeur_min - ret);
	write(1, line, ret);
	free(line);
	return (ret + sp);
}