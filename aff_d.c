/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:07:16 by safernan          #+#    #+#             */
/*   Updated: 2021/01/25 18:08:27 by safernan         ###   ########.fr       */
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

static int	taille(int nb, t_arg *arg)
{
	int		i;
	int		x;
	long	n;

	n = nb;
	if (n < 0)
		n = -n;
	x = 1;
	i = 1;
	while (n / x > 9)
	{
		x = 10 * x;
		i++;
	}
	if (arg->precision == 1 && arg->longeur > i)
		i = arg->longeur;
	i += (nb < 0);
	if (arg->zero == 1 && arg->larg_min > i)
		i = arg->larg_min;
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
	(*line)[0] = '0';
	return (1);
}

static int	insert(t_arg *arg, int nb, char **line)
{
	int		len;
	int		ret;
	long	n;

	n = nb;
	len = taille(nb, arg);
	if (!(*line = malloc(len + 1)))
		return (-1);
	if (nb < 0)
	{
		ret = ft_itoa_base("0123456789", -n, line) + 1;
		shift(line);
	}
	else
		ret = ft_itoa_base("0123456789", nb, line);
	while (ret < len)
	{
		shift(line);
		ret++;
	}
	if (nb < 0)
		(*line)[0] = '-';
	if (arg->longeur == 0 && nb == 0)
		return (0);
	return (len);
}

int			aff_di(t_arg *arg, va_list ap)
{
	int		nb;
	char	*line;
	int		ret;
	int		sp;

	if (arg->s_longeur == 1)
		arg->longeur = va_arg(ap, int);
	nb = va_arg(ap, int);
	if ((ret = insert(arg, nb, &line)) == -1)
		return (-1);
	if (arg->moins)
	{
		write(1, line, ret);
		free(line);
		return (ret + blank(arg, arg->larg_min - ret));
	}
	sp = blank(arg, arg->larg_min - ret);
	write(1, line, ret);
	free(line);
	return (ret + sp);
}
