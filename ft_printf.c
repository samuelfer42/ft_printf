/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:34:54 by safernan          #+#    #+#             */
/*   Updated: 2020/02/05 20:24:57 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		affiche_et_ajoute(char c, int *i, int *len)
{
	write(1, &c, 1);
	(*i)++;
	(*len)++;
	return (1);
}

int				ft_printf(const char *s, ...)
{
	va_list		ap;
	int			len;
	int			i;
	int			ret;

	if (!s)
		return (-1);
	va_start(ap, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if ((ret = verif_arg(s, &i, ap)) == -1)
				return (-1);
			len += ret;
		}
		if (s[i] != '%')
			affiche_et_ajoute(s[i], &i, &len);
	}
	va_end(ap);
	return (len);
}
