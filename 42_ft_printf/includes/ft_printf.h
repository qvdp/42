#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

/*
 *
 * LIST DEFINITION
 *
 */

typedef struct       s_var
{
	int                width;
	int                flag;
  int                precision;
	int								type;
	char							*size;
  struct s_var		*next;
}					        	t_var;

/*
 *
 * MAIN FUNCTIONS
 *
 */
int		ft_printf(const char *format, ...);
int		ft_type_parser(const char **format, va_list *args);

/*
 *
 * FLAGS HANDLER
 *
 */
int	ft_d_type(va_list *args);
int	ft_u_type(va_list *args);
int	ft_c_type(va_list *args);
int	ft_s_type(va_list *args);

#endif
