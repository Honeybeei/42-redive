/**
 * @brief Checks if the given character is an alphabetic character.
 *
 * @param c
 * @return int
 */
int ft_isalpha(int c) {
  return (
      // Check if the character is an uppercase or lowercase letter.
      (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
