#include "libft.h"

/**
 * @brief Checks if the given character is alphanumeric.
 *
 * @param c
 * @return int
 */
int ft_isalnum(int c) { return (ft_isalpha(c) || ft_isdigit(c)); }