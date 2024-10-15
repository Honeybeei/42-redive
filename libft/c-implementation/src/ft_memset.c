#include "libft.h"

/**
 * @brief Fills the first n bytes of the memory area pointed to by s with the
 * constant byte c.
 *
 * @param s
 * @param c
 * @param n
 * @return void*
 */

void *ft_memset(void *s, int c, size_t n) {
  unsigned char *p = s;
  while (n) {
    *p = (unsigned char)c;
    p++;
    n--;
  }
  return s;
}