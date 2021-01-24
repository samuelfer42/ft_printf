/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:01:09 by safernan          #+#    #+#             */
/*   Updated: 2021/01/24 16:02:46 by safernan         ###   ########.fr       */
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
