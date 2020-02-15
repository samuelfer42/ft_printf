/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:35:16 by safernan          #+#    #+#             */
/*   Updated: 2020/02/02 17:12:57 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_arg
{
	int			moins;
	int			zero;
	int			largeur_min;
	int			precision;
	int			longueur;
	int			s_longueur;
	char		format;
}				t_arg;

int				aff_s(t_arg *arg, va_list ap);
int				aff_p(t_arg *arg, va_list ap);
int				aff_di(t_arg *arg, va_list ap);
int				aff_u(t_arg *arg, va_list ap);
int				aff_x(t_arg *arg, va_list ap);
int				aff_xx(t_arg *arg, va_list ap);
int				ft_printf(const char *s, ...);
int				ft_atoi(const char *s);
int				ft_itoa_base(char *base, unsigned long nb, char **line);
int				ft_printarg(const char *s, int *i, va_list ap);
int				remplir_stucture(const char *s, t_arg *arg, va_list ap);
#endif
