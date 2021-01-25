#include "ft_printf.h"

int	main(int ac, char **av)
{
  int	ret[2];
  char	*str = "astek";


  printf(   "   Caractere [c] : {%c}\n", 42);
  ft_printf("=> Caractere [c] : {%c}\n", 42);
 printf("\n");
  printf(   "   Chaine [s] : {%s}\n", str);
  ft_printf("=> Chaine [s] : {%s}\n", str);
printf("\n");
  printf(   "   Pointeur [p] : {%p}\n", str);
  ft_printf("=>  Pointeur [p] : {%p}\n", str);
printf("\n");
  printf(   "   Nombre signe [d] : {%d}\n", 42);
  ft_printf("=> Nombre signe [d] : {%d}\n", 42);
 printf("\n");
  printf(   "   Modulo [%%] : {%%}\n");
  ft_printf("=> Modulo [%%] : {%%}\n");
 printf("\n");

  printf(   "   Nombre signe [i] : {%i}\n", 42);
  ft_printf("=> Nombre signe [i] : {%i}\n", 42);
 printf("\n");
  printf(   "   Nombre non signe [u] : {%u}\n", 42);
  ft_printf("=> Nombre non signe [u] : {%u}\n", 42);
 printf("\n");
  printf(   "   Nombre hexadecimal [x] : {%x}\n", 0x12345);
  ft_printf("=> Nombre hexadecimal [x] : {%x}\n", 0x12345);
 printf("\n");
  printf(   "   Nombre hexadecimal [X] : {%X}\n", 0x12345);
  ft_printf("=> Nombre hexadecimal [X] : {%X}\n", 0x12345);
 printf("\n");

  printf(   "   Pointeur [p] : {%p}\n", str);
  ft_printf("=>  Pointeur [p] : {%p}\n", str);
printf("\n");
  printf(   "   Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
  ft_printf("=> Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
printf("\n");
  printf(   "   Affichage multiple [d d d] : {%d} {%d} {%d}\n", -0, -42, -2147483648);
  ft_printf("=> Affichage multiple [d d d] : {%d} {%d} {%d}\n", -0, -42, -2147483648);
printf("\n");
  printf(   "   Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
  ft_printf("=> Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
printf("\n");
  printf(   "   Affichage multiple [X p d] : {%X} {%p} {%d}\n", 0x12345, str, 42);
  ft_printf("=> Affichage multiple [X p d] : {%X} {%p} {%d}\n", 0x12345, str, 42);
printf("\n");
  printf(   "   Affichage long [d d d ...] : %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC);
  ft_printf("=> Affichage long [d d d ...] : %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC);
printf("\n");
  printf(   "   Formatage simple [0d] : {%0d}\n", 42);
  ft_printf("=> Formatage simple [0d] : {%0d}\n", 42);
printf("\n");
  printf(   "   Formatage simple [5d] : {%5d}\n", 42);
  ft_printf("=> Formatage simple [5d] : {%5d}\n", 42);
printf("\n");
  printf(   "   Formatage simple [-d] : {%-d}\n", 42);
  ft_printf("=> Formatage simple [-d] : {%-d}\n", 42);
printf("\n");
  printf(   "   Formatage ultracompose [0*d]  : {%0*d}\n",  5, 3 );
  ft_printf("=> Formatage ultracompose [0*d]  : {%0*d}\n",  5, 3 );
printf("\n");
  printf(   "   Formatage ultracompose [#-6.3d] : {%#-6.3d}\n", -2147483648);
  ft_printf("=>  Formatage ultracompose [#-6.3d] : {%#-6.3d}\n", -2147483648);
printf("\n");
  printf(   "   Formatage pourcent [30%%] : {%30%}\n");
  ft_printf("=> Formatage pourcent [30%%] : {%30%}\n");
printf("\n");
  printf(   "   Formatage pourcent [-30pourcent] : {%-30%}\n");
  ft_printf("=> Formatage pourcent [-30pourcent] : {%-30%}\n");
printf("\n");
  ret[0] = printf(   "   Test de la valeur de retour [-10d s] : {%-10d} {%s}\n", 12345, str);
  ret[1] = ft_printf("=> Test de la valeur de retour [-10d s] : {%-10d} {%s}\n", 12345, str);
printf("\n");
  printf(   "   Verification de la valeur de retour [d] : {%d}\n", ret[0]);
  ft_printf("=> Verification de la valeur de retour [d] : {%d}\n", ret[1]);
printf("\n");
  printf(   "   Test de pile [c c] : {%c} {%c}\n", 0x4142434444434241);
  ft_printf("=> Test de pile [c c] : {%c} {%c}\n", 0x4142434444434241);

  return(0);
}
