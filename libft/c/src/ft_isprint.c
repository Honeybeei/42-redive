#include "libft.h"

/**
 * @brief Checks if the given character is a printable character.
 *
 * @param c
 * @return int
 */
int ft_isprint(int c) { return (c >= 32 && c <= 126); };