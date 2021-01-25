/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:03:55 by safernan          #+#    #+#             */
/*   Updated: 2021/01/25 18:08:27 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	blank(char c, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	aff_mod(t_arg *arg)
{
	char	c;

	c = ' ';
	if (arg->moins == 1)
		return (ft_putchar('%') + blank(c, arg->larg_min - 1));
	if (arg->zero == 1)
		c = '0';
	return (blank(c, arg->larg_min - 1) + ft_putchar('%'));
}

static int	aff_c(t_arg *arg, va_list ap)
{
	char	c;
	char	ch;

	c = ' ';
	ch = va_arg(ap, int);
	if (arg->moins == 1)
		return (ft_putchar(ch) + blank(c, arg->larg_min - 1));
	if (arg->zero == 1)
		c = '0';
	return (blank(c, arg->larg_min - 1) + ft_putchar(ch));
}

int			verif_arg(const char *s, int *i, va_list ap)
{
	t_arg	arg;
	int		ret;

	if ((ret = remplir_struct(s + *i, &arg, ap)) < 0)
		return (-1);
	(*i) += ret;
	if (arg.format == 'c')
		return (aff_c(&arg, ap));
	if (arg.format == 's')
		return (aff_s(&arg, ap));
	if (arg.format == 'p')
		return (aff_p(&arg, ap));
	if (arg.format == 'd' || arg.format == 'i')
		return (aff_di(&arg, ap));
	if (arg.format == 'u')
		return (aff_u(&arg, ap));
	if (arg.format == 'x')
		return (aff_x(&arg, ap));
	if (arg.format == 'X')
		return (aff_xx(&arg, ap));
	if (arg.format == '%')
		return (aff_mod(&arg));
	return (-1);
}
