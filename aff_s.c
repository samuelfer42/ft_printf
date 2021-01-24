/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:02:20 by safernan          #+#    #+#             */
/*   Updated: 2021/01/24 16:02:57 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

static int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	blank(char c, t_arg *arg, char *ctnt)
{
	int		i;
	int		len;

	len = ft_strlen(ctnt);
	if (arg->precision == 1 && arg->longeur >= 0 && len > arg->longeur)
		len = arg->longeur;
	if (arg->largeur_min == -1 || len >= arg->largeur_min)
		return (0);
	i = 0;
	while (i + len < arg->largeur_min)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

static int	insert(t_arg *arg, char *ctnt)
{
	int		i;

	i = 0;
	if (arg->precision == 1 && arg->longeur == 0)
		return (0);
	while (ctnt[i])
	{
		if (arg->precision == 1 && arg->longeur >= 0 && i == arg->longeur)
			break ;
		i++;
	}
	write(1, ctnt, i);
	return (i);
}

int			aff_s(t_arg *arg, va_list ap)
{
	char	*ctnt;
	char	c;

	c = ' ';
	if (arg->zero == 1)
		c = '0';
	if (arg->s_longeur == 1)
		arg->longeur = va_arg(ap, int);
	if (!(ctnt = va_arg(ap, char*)))
		ctnt = "(null)";
	if (arg->precision == 1 && arg->longeur == 0)
		ctnt = "";
	if (arg->moins == 1)
		return (insert(arg, ctnt) + blank(c, arg, ctnt));
	return (blank(c, arg, ctnt) + insert(arg, ctnt));
}
