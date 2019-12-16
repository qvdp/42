#include "../includes/ft_printf.h"
#include <stdio.h>

// However, for input data (e.g.: scanf) you can use %i for scanning hexadecimal values (if preceded by 0x), or octal (if preceded by 0). Its default behavior will scan decimal values.
//
// E.g: if you input some data using %i like 0x28, it will be the same as 40 in dec.

// #include <stdio.h>
// int main(){
//     int dec, hex;
//     scanf("%i",&hex); //For example, hex = 0x28
//     scanf("%d",&dec); //For example, dec = 28
//     printf("Hex: %d\nDec: %d\n",hex,dec); // outputs: Hex = 40, Dec = 28;
// }
int	ft_i_type(va_list *args) // TO DO cf upper
{
	int d;

	d = va_arg(*args, int);
	ft_putnbr(d);
	return (1);
}


int	ft_d_type(va_list *args)
{
	int d;

	d = va_arg(*args, int);
	ft_putnbr(d);
	return (1);
}

int	ft_u_type(va_list *args)
{
	unsigned int d;

	d = va_arg(*args, unsigned int);
	ft_putnbr(d);
	return (1);
}

int	ft_o_type(va_list *args)
{
	int d;
	d = va_arg(*args, int);
	ft_putoct(d);
	return (1);
}

int	ft_x_type(va_list *args)
{
	int d;
	d = va_arg(*args, int);
	ft_puthex_lower(d);
	return (1);
}

int	ft_X_type(va_list *args)
{
	int d;
	d = va_arg(*args, int);
	ft_puthex_upper(d);
	return (1);
}
