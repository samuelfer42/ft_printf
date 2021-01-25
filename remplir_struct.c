/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplir_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:03:23 by safernan          #+#    #+#             */
/*   Updated: 2021/01/25 18:08:31 by safernan         ###   ########.fr       */
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
	arg->larg_min = -1;
	if (s[i] == '*')
	{
		arg->larg_min = va_arg(ap, int);
		if (arg->larg_min < 0)
		{
			arg->larg_min = -arg->larg_min;
			arg->moins = 1;
		}
		i++;
	}
	else if (cherche_caractere(s[i], "0123456789"))
	{
		arg->larg_min = ft_atoi(s + i);
		while (cherche_caractere(s[i], "0123456789"))
			i++;
	}
	return (i);
}

static int		remplir_precision(const char *s, t_arg *arg, int i, va_list ap)
{
	arg->precision = 0;
	arg->s_longeur = 0;
	arg->longeur = -1;
	if (s[i] == '.')
	{
		arg->precision = 1;
		i++;
		if (s[i] == '*')
		{
			arg->longeur = va_arg(ap, int);
			i++;
		}
		else if (cherche_caractere(s[i], "-0123456789"))
		{
			arg->longeur = ft_atoi(s + i);
			while (cherche_caractere(s[i], "-0123456789"))
				i++;
			arg->larg_min = (arg->longeur < 0) ? -arg->longeur : arg->larg_min;
			arg->moins = (arg->longeur < 0) ? 1 : arg->moins;
			arg->longeur = (arg->longeur < 0) ? 0 : arg->longeur;
		}
		else
			arg->longeur = 0;
	}
	return (i);
}

int				remplir_struct(const char *s, t_arg *arg, va_list ap)
{
	int		i;

	i = remplir_flags(s, arg);
	i = remplir_largeur(s, arg, i, ap);
	i = remplir_precision(s, arg, i, ap);
	if (arg->zero == 1 && arg->moins == 1)
		arg->zero = 0;
	if (cherche_caractere(s[i], "cspdiuxX%"))
	{
		arg->format = s[i];
		if (arg->zero && arg->precision && arg->longeur >= 0
			&& cherche_caractere(s[i], "spdiuxX"))
			arg->zero = 0;
		return (i + 1);
	}
	return (-1);
}
