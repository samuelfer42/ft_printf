/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:02:16 by safernan          #+#    #+#             */
/*   Updated: 2021/01/24 16:02:57 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

static int	blank(t_arg *arg, int nb)
{
	int		i;
	char	c;

	c = ' ';
	if (arg->zero == 1)
		c = '0';
	i = 0;
	while (i < nb)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

static int	taille(unsigned int nb, t_arg *arg)
{
	int				i;
	unsigned int	x;

	x = 1;
	i = 1;
	while (nb / x > 9)
	{
		x = 10 * x;
		i++;
	}
	if (arg->precision == 1 && arg->longeur > i)
		return (arg->longeur);
	return (i);
}

static int	shift(char **line)
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

static int	insert(t_arg *arg, unsigned int nb, char **line)
{
	int		len;
	int		ret;

	len = taille(nb, arg);
	if (!(*line = malloc(len + 1)))
		return (-1);
	ret = ft_itoa_base("0123456789", nb, line);
	while (ret < len)
	{
		shift(line);
		(*line)[0] = '0';
		ret++;
	}
	if (arg->longeur == 0 && nb == 0)
		return (0);
	return (len);
}

int			aff_u(t_arg *arg, va_list ap)
{
	unsigned int	nb;
	char			*line;
	int				ret;
	int				sp;

	if (arg->s_longeur == 1)
		arg->longeur = va_arg(ap, int);
	nb = va_arg(ap, unsigned int);
	if ((ret = insert(arg, nb, &line)) == -1)
		return (-1);
	if (arg->moins)
	{
		write(1, line, ret);
		free(line);
		return (ret + blank(arg, arg->largeur_min - ret));
	}
	sp = blank(arg, arg->largeur_min - ret);
	write(1, line, ret);
	free(line);
	return (ret + sp);
}
