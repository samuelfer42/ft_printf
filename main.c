/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:51:54 by safernan          #+#    #+#             */
/*   Updated: 2020/02/02 17:20:48 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

//int		ft_printf(const char *str, ...)
//{
 //  va_list	varg;
//va_start (varg, str);
//   int 	i;
//   i = -1;
   
//   while(str != '\0')
//   {
//	   	printf("%s", str);
//    	str = va_arg (varg, void *);

//		putchar ('\n');
//   }
//   putchar ('\n');
//   va_end (varg);
//   return(i);
//}

int 	main (void)
{
	int	i=1;
	int b=6;
	i += b;
	
   ft_printf("%0d", i);
   ft_printf("\n");
   printf("%02d", b);

   return 0;
}
