#ifndef FT_HEADER_H
# define FT_HEADER_H

#include <string.h>
#include <stdlib.h>

char	*ft_strcat(char *restrict s1, char *restrict s2);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
size_t			ft_strlen(const char *str);
char	*ft_strncat(char *restrict s1, char *restrict s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strstr(const char *haystack, const char *needle);
long				ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

#endif
