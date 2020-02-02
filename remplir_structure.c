/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplir_stucture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:30:39 by safernan          #+#    #+#             */
/*   Updated: 2020/01/18 15:35:52 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		cherche_caractere(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (str[i] == c);
}

static int		remplir_flags(const char *s, t_arg *arg)
{
	int		i;

	i = 1;
	arg->moins = 0;
	arg->zero = 0;
	while (cherche_caractere(s[i], "-0+#"))
	{
		if (s[i] == '-')
			arg->moins = 1;
		if (s[i] == '0')
			arg->zero = 1;
		i++;
	}
	return (i);
}

static int		remplir_largeur(const char *s, t_arg *arg, int i, va_list ap)
{
	arg->largeur_min = -1;
	if (s[i] == '*')
	{
		arg->largeur_min = va_arg(ap, int);
		if (arg->largeur_min < 0)
		{
			arg->largeur_min = -arg->largeur_min;
			arg->moins = 1;
		}
		i++;
	}
	else if (cherche_caractere(s[i], "0123456789"))
	{
		arg->largeur_min = ft_atoi(s + i);
		while (cherche_caractere(s[i], "0123456789"))
			i++;
	}
	return (i);
}

static int		remplir_precision(const char *s, t_arg *arg, int i, va_list ap)
{
	arg->precision = 0;
	arg->s_longueur = 0;
	arg->longueur = -1;
	if (s[i] == '.')
	{
		arg->precision = 1;
		i++;
		if (s[i] == '*')
		{
			arg->longueur = va_arg(ap, int);
			i++;
		}
		else if (cherche_caractere(s[i], "-0123456789"))
		{
			arg->longueur = ft_atoi(s + i);
			while (cherche_caractere(s[i], "-0123456789"))
				i++;
			arg->largeur_min = (arg->longueur < 0) ? -arg->longueur : arg->largeur_min;
			arg->moins = (arg->longueur < 0) ? 1 : arg->moins;
			arg->longueur = (arg->longueur < 0) ? 0 : arg->longueur;
		}
		else
			arg->longueur = 0;
	}
	return (i);
}

int				remplir_stucture(const char *s, t_arg *arg, va_list ap)
{
	int		i;

	i = remplir_flags(s, arg);
	i = remplir_largeur(s, arg, i, ap);
	i = remplir_precision(s, arg, i, ap);
	if (arg->zero == 1 && arg->moins == 1)
		arg->zero = 0;
	if (cherche_caractere(s[i], "cspdiuxX%"))
	{
		arg->type = s[i];
		if (arg->zero && arg->precision && arg->longueur >= 0
			&& cherche_caractere(s[i], "spdiuxX"))
			arg->zero = 0;
		return (i + 1);
	}
	return (-1);
}
