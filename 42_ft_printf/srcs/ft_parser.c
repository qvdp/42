#include "../includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_final_parser(va_list *args, t_var **element)
{
	printf("%p",args);
	printf(" --- DETAILED ARG --- \n");
	if ((*element)->width)
		printf(" - Width: %d\n", (*element)->width);
	if ((*element)->flag)
		printf(" - Flag : %c\n", (*element)->flag);
	if ((*element)->precision)
		printf(" - Prec.: %d\n", (*element)->precision);
	// if (**format && ((*element)->type = **format))
	// 	printf(" - Type : %c\n", (*element)->type);
	if ((*element)->size)
		printf(" - Size : %s\n", (*element)->size);
	return 0;
}

int	ft_size_parser(const char **format, va_list *args, t_var **element)
{
	// ✓ [size]
	// ✓ h : short int / short unsigned int [d, i, o, u, x, X]
	// ✓ hh : char / unsigned char [d, i, o, u, x, X]
	// ✓ l : long int / long unsigned int [d, i, o, u, x, X, f]
	// ✓ ll : long long int / unsigned long long int [d,i,o,u,x,X]
	// ✓ L : long double [f]
	int is_handled;

	is_handled = 0;
	if (**format == 'h')
	{
		*format += 1;
		is_handled = **format == 'h' ? 2 : 1;
	}
	else if (**format == 'l')
	{
		*format += 1;
		is_handled = **format == 'l' ? 2 : 1;
	}
	else if (**format == 'L')
	{
		*format += 1;
		is_handled = 1;
	}

	if (is_handled > 0)
	{
		if (((*element)->size = (char*)malloc(sizeof(char) * is_handled + 1)))
		{
			int i = 0;
			while (is_handled)
			{
				ft_putstr("malloc");
				(*element)->size[i] = **format;
				is_handled--;
				i++;
			}
			(*element)->size[i] = '\0';
			*format += 1;
		}
		else
			return 0;
	} else {
		if (((*element)->size = (char*)malloc(sizeof(char))))
			(*element)->size = "!";
		else
			return 0;
	}

	return (ft_final_parser(args, element));
}

int	ft_precision_parser(const char **format, va_list *args, t_var **element)
{
	// ✓ [.precision]
	int precision;

	precision = 0;
	if (**format == '.')
	{
		*format += 1;
		if ((precision = ft_atoi(*format)) > 0)
			(*element)->precision = precision;
		while ((precision /= 10) > 0)
			*format += 1;
		*format+=1;
	} else {
		(*element)->precision = -1;
	}

	return (ft_size_parser(format, args, element));
}

int	ft_width_parser(const char **format, va_list *args, t_var **element)
{
	// ✓ [.width]
	int width;

	if ((width = ft_atoi(*format)) && width >= 0)
	{
		if (*element)
			(*element)->width = width;
		while ((width /= 10) > 0)
			*format += 1;
		*format+=1;
	} else {
		(*element)->width = -1;
	}

	return (ft_precision_parser(format, args, element));
}

int	ft_flags_parser(const char **format, va_list *args) // OR check width * ou NUMBER
{
	// ✓ # : Utilisé avec les conversions o, x, X. Applique automatiquement le 0 pour préfixer la valeur de sortie. (Quelle différence entre ça et mettre 0 tout simplement ?)
	// ✓ 0 : Si [width] est préfixée par 0, alors, tout les espaces vide précédent la valeur sont rempli de 0 non significatif.
	//  - Ignoré si utilisé avec le flag -
	//  - Ignoré si utilisé avec les conversions i, u, x, X, o, d et qu'une précision est indiquée.
	// ✓ - : Aligne le resultat vers la gauche si [width] est supérieur à ce dernier.
	// ✓ + : Préfixe la valeur de sortie d'un avec un signe + ou - en fonction de si cette dernière est positive ou non, pour un type signé.
	// ✓ Space : Préfixe d'un espace si la valeur de sortie est positive ou d'un - si cette dernière est négative.
	int is_handled;
	t_var 	*element;

	element = NULL;
	is_handled = 0;
	is_handled += (!is_handled && **format == ' ') ? 1 : 0;
	is_handled += (!is_handled && **format == '-') ? 1 : 0;
	is_handled += (!is_handled && **format == '+') ? 1 : 0;
	is_handled += (!is_handled && **format == '0') ? 1 : 0;

	// As we can not identify type on first try, we build a list to handle the argument and its flags
	if (((element = (t_var*)malloc(sizeof(t_var)))) && is_handled)
	{
		element->flag = **format;
		*format += 1;
	} else if (element && !is_handled) {
		//If no flags are founded, fill with `!` char
		element->flag = 33;
	} else {
		// Malloc failed
		return 0;
	}

	return (ft_width_parser(format, args, &element));
}

int	ft_type_parser(const char **format, va_list *args)
{
	// ✓ c : Char (int)
	// ✓ s : Chaine de caractère (char*)
	// ✓ p : Adresse d'un pointeur en hexadécimal (void*)
	// ✓ d : Converti en entier décimal signé (int)
	// ✓ i : Converti en entier décimal signé (int)
	// ✓ o : Converti en entier octal non signé (unsigned int)
	// ✓ u : Converti en entier décimal non signé (unsigned int)
	// ✓ x : Converti en entier hexadécimal non signé avec lettre en minuscule (unsigned int)
	// ✓ X : Converti en entier hexadécimal non signé avec lettre en majuscule (unsigned int)
	// - f : Converti en chiffre a virgule. Le nombre de chiffre après la virgule dépend de la précision. (6 par défaut) (double)
	int is_handled;

	if (**format == '%')
		*format += 1;

	is_handled = 0;

	// Handle int
	is_handled += (!is_handled && **format == 'd') ? ft_d_type(args) : 0;
	is_handled += (!is_handled && **format == 'u') ? ft_u_type(args) : 0;
	is_handled += (!is_handled && **format == 'i') ? ft_i_type(args) : 0;
	is_handled += (!is_handled && **format == 'o') ? ft_o_type(args) : 0;
	is_handled += (!is_handled && **format == 'x') ? ft_x_type(args) : 0;
	is_handled += (!is_handled && **format == 'X') ? ft_X_type(args) : 0;
	// Handle string
	is_handled += (!is_handled && **format == 'c') ? ft_c_type(args) : 0;
	is_handled += (!is_handled && **format == 's') ? ft_s_type(args) : 0;
	is_handled += (!is_handled && **format == 'p') ? ft_p_type(args) : 0;
	//if (is_handled)
	//	*format += 1;
	is_handled += (!is_handled && **format == '%') ? write(1,"%%",2) : 0;

	return (is_handled ? 0 : ft_flags_parser(format, args));
}
