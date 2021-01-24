/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:02:23 by safernan          #+#    #+#             */
/*   Updated: 2021/01/24 16:03:01 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

static int	blank(int nb)
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

static int	taille(unsigned long nb)
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

static int	insert(unsigned long nb, char **line)
{
	int		len;
	int		ret;

	len = taille(nb);
	if (!(*line = malloc(len + 1)))
		return (-1);
	ret = ft_itoa_base("0123456789abcdef", nb, line);
	shift(line);
	shift(line);
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

	if (arg->s_longeur == 1)
		arg->longeur = va_arg(ap, int);
	nb = (unsigned long)va_arg(ap, void *);
	if (arg->precision == 1 || arg->zero == 1)
		return (-1);
	if ((ret = insert(nb, &line)) == -1)
		return (-1);
	if (arg->moins)
	{
		write(1, line, ret);
		free(line);
		return (ret + blank(arg->largeur_min - ret));
	}
	sp = blank(arg->largeur_min - ret);
	write(1, line, ret);
	free(line);
	return (ret + sp);
}
