#include "libft.h"

/**
 * @brief Returns the length of the given string.
 *
 * @param s
 * @return size_t
 */

size_t ft_strlen(const char *s) {
  size_t i = 0;
  while (s[i] != '\0') i++;
  return i;
}