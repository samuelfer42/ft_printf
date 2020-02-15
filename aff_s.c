/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:32:40 by safernan          #+#    #+#             */
/*   Updated: 2020/01/18 15:35:47 by safernan         ###   ########.fr       */
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

static int	ft_blank(char c, t_arg *arg, char *str)
{
	int		i;
	int		len;

	len = ft_strlen(str);
	if (arg->precision == 1 && arg->longueur >= 0 && len > arg->longueur)
		len = arg->longueur;
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

static int	ft_put(t_arg *arg, char *str)
{
	int		i;

	i = 0;
	if (arg->precision == 1 && arg->longueur == 0)
		return (0);
	while (str[i])
	{
		if (arg->precision == 1 && arg->longueur >= 0 && i == arg->longueur)
			break ;
		i++;
	}
	write(1, str, i);
	return (i);
}

int			aff_s(t_arg *arg, va_list ap)
{
	char	*str;
	char	c;

	c = ' ';
	if (arg->zero == 1)
		c = '0';
	if (arg->s_longueur == 1)
		arg->longueur = va_arg(ap, int);
	if (!(str = va_arg(ap, char*)))
		str = "(null)";
	if (arg->precision == 1 && arg->longueur == 0)
		str = "";
	if (arg->moins == 1)
		return (ft_put(arg, str) + ft_blank(c, arg, str));
	return (ft_blank(c, arg, str) + ft_put(arg, str));
}
