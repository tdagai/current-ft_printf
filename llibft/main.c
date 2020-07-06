
#include "libft.h"
#include <stdio.h>

int		main() 
{
	long double i = 23.000041;
	
	char *str;

	str = ft_dtoa_for_g(&str, i, 6, 10);

	printf("%s|\n", str);

//	char *str;
//	char *str2;

/*	str = ft_dtoa_for_g(i, prec, 10);
	str2 = ft_dtoa(i, prec, 10);

	printf("dtoa:		|%s|\n", str2);
	printf("dtoa_for_g:	|%s|\n", str);
*/
}

