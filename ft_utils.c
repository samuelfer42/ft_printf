/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:35:31 by safernan          #+#    #+#             */
/*   Updated: 2020/01/18 15:35:33 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *s)
{
	int		sgn;
	long	val;
	int		i;

	val = 0;
	i = 0;
	sgn = 1;
	while (s[i] == '-')
	{
		sgn = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		val = 10 * val + s[i] - '0';
		i++;
	}
	return (val * sgn);
}
