/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:03:06 by qvan-der          #+#    #+#             */
/*   Updated: 2018/11/14 19:07:59 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_words(char const *s, char c)
{
  size_t i;
  size_t count;

  i = 0;
  count = 0;
  while (s[i])
  {
    while (s[i] == c && s[i])
      i++;
    if (s[i])
      count++;
    while (s[i] != c && s[i])
      i++;
  }
  return (count);
}

char	**ft_strsplit(char const *s, char c)
{
  char **str;
  unsigned int start;
  size_t words;
  size_t count;
  size_t len;

  if (!s)
    return (NULL);
  if (!(str = (char**)malloc(sizeof(char) * (words = ft_words(s, c)) + 1)))
    return (NULL);
  count = 0;
  start = 0;
  while (count < words)
  {
    len = 0;
    while (s[start] == c)
      start++;
    while (s[start + len] != c && s[start + len])
      len++;
    str[count++] = ft_strsub(s, start, len);
    start += len;
  }
  str[count] = NULL;
  return(str);
}
