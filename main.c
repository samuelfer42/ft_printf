/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:51:54 by safernan          #+#    #+#             */
/*   Updated: 2020/01/18 15:53:06 by safernan         ###   ########.fr       */
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
   ft_printf("%s", "Def");
   ft_printf("\n");
   printf("%s", "test");

   return 0;
}
