/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:01:52 by safernan          #+#    #+#             */
/*   Updated: 2021/01/25 18:08:27 by safernan         ###   ########.fr       */
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
	int			larg_min;
	int			precision;
	int			longeur;
	int			s_longeur;
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
int				verif_arg(const char *s, int *i, va_list ap);
int				remplir_struct(const char *s, t_arg *arg, va_list ap);
#endif
