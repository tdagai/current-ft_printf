
#include "ft_printf_bonus.h"

int main ()
{
	double	i = 0.000039;
/*
	char	*str;
	char	*str_teva;

	str = ft_dtoa_for_g(i, 10, 10);
	printf("%s\n", str);
	i = 23.0024;
	str_teva = ft_dtoa_for_g(i, 10, 10);
	printf("%s\n", str_teva);
*/
//	printf("Libc e:	%.5e|\n", i);
//	printf("Libc f:	%.10f|\n", i);
//	printf("Libc g:	%g|\n\n", i);
	
	ft_printf("Mine g:	%g|\n", i);
}

