#include "libft.h"

/**
 * @brief Checks if the given character is in the ASCII character set.
 *
 * @param c
 * @return int
 */
int ft_isascii(int c) { return (c >= 0 && c <= 127); }