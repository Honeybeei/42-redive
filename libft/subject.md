# libft

## Introduction

This project is the first project of the 42 common core curriculum. The goal is to create a library of useful functions that will be used in future projects.

## Functions to implement

### Part 1 - Libc functions

- [x] `ft_isalpha` - Prototype: `int ft_isalpha(int c);`
  - Parameters:
    - `c`: The character to be checked.
  - Return value: Non-zero if the character is alphabetic, 0 otherwise.
  - Description: Checks if the given character is an alphabetic character.

- [x] `ft_isdigit` - Prototype: `int ft_isdigit(int c);`
  - Parameters:
    - `c`: The character to be checked.
  - Return value: Non-zero if the character is a digit, 0 otherwise.
  - Description: Checks if the given character is a digit (0 through 9).

- [x] `ft_isalnum` - Prototype: `int ft_isalnum(int c);`
  - Parameters:
    - `c`: The character to be checked.
  - Return value: Non-zero if the character is alphanumeric, 0 otherwise.
  - Description: Checks if the given character is alphanumeric.

- [x] `ft_isascii` - Prototype: `int ft_isascii(int c);`
  - Parameters:
    - `c`: The character to be checked.
  - Return value: Non-zero if the character is in the ASCII character set, 0 otherwise.
  - Description: Checks if the given character is in the ASCII character set.

- [ ] `ft_isprint` - Prototype: `int ft_isprint(int c);`
  - Parameters:
    - `c`: The character to be checked.
  - Return value: Non-zero if the character is printable, 0 otherwise.
  - Description: Checks if the given character is a printable character.

- [ ] `ft_strlen` - Prototype: `size_t ft_strlen(const char *s);`
  - Parameters:
    - `s`: The string to be measured.
  - Return value: The number of characters in the string.
  - Description: Calculates the length of the given string.

- [ ] `ft_memset` - Prototype: `void *ft_memset(void *b, int c, size_t len);`
  - Parameters:
    - `b`: Pointer to the memory area to be filled.
    - `c`: The value to be set (converted to an unsigned char).
    - `len`: The number of bytes to be set.
  - Return value: A pointer to the memory area `b`.
  - Description: Fills the first `len` bytes of the memory area pointed to by `b` with the constant byte `c`.

- [ ] `ft_bzero` - Prototype: `void ft_bzero(void *s, size_t n);`
  - Parameters:
    - `s`: Pointer to the memory area to be zeroed.
    - `n`: The number of bytes to be zeroed.
  - Description: Erases the data in the `n` bytes of the memory starting at the location pointed to by `s`, by writing zeros (bytes containing '\0') to that area.

- [ ] `ft_memcpy` - Prototype: `void *ft_memcpy(void *dst, const void *src, size_t n);`
  - Parameters:
    - `dst`: Pointer to the destination array.
    - `src`: Pointer to the source array.
    - `n`: The number of bytes to be copied.
  - Return value: A pointer to the destination array.
  - Description: Copies `n` bytes from memory area `src` to memory area `dst`. The memory areas must not overlap.

- [ ] `ft_memmove` - Prototype: `void *ft_memmove(void *dst, const void *src, size_t len);`
  - Parameters:
    - `dst`: Pointer to the destination array.
    - `src`: Pointer to the source array.
    - `len`: The number of bytes to be copied.
  - Return value: A pointer to the destination array.
  - Description: Copies `len` bytes from memory area `src` to memory area `dst`. The memory areas may overlap.

- [ ] `ft_strlcpy` - Prototype: `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);`
  - Parameters:
    - `dst`: Pointer to the destination array.
    - `src`: Pointer to the source string.
    - `dstsize`: Size of the destination buffer.
  - Return value: The total length of the string they tried to create (length of `src`).
  - Description: Copies up to `dstsize - 1` characters from the string `src` to `dst`, NUL-terminating the result if `dstsize` is not 0.

- [ ] `ft_strlcat` - Prototype: `size_t ft_strlcat(char *dst, const char *src, size_t dstsize);`
  - Parameters:
    - `dst`: Pointer to the destination array.
    - `src`: Pointer to the source string.
    - `dstsize`: Size of the destination buffer.
  - Return value: The initial length of `dst` plus the length of `src`.
  - Description: Appends string `src` to the end of `dst`. It will append at most `dstsize - strlen(dst) - 1` characters.

- [ ] `ft_toupper` - Prototype: `int ft_toupper(int c);`
  - Parameters:
    - `c`: The character to be converted.
  - Return value: The uppercase equivalent if the character is lowercase, otherwise the character itself.
  - Description: Converts a lowercase letter to the corresponding uppercase letter.

- [ ] `ft_tolower` - Prototype: `int ft_tolower(int c);`
  - Parameters:
    - `c`: The character to be converted.
  - Return value: The lowercase equivalent if the character is uppercase, otherwise the character itself.
  - Description: Converts an uppercase letter to the corresponding lowercase letter.

- [ ] `ft_strchr` - Prototype: `char *ft_strchr(const char *s, int c);`
  - Parameters:
    - `s`: The string to be scanned.
    - `c`: The character to be searched.
  - Return value: A pointer to the first occurrence of the character `c` in the string `s`, or NULL if the character is not found.
  - Description: Locates the first occurrence of `c` (converted to a char) in the string pointed to by `s`.

- [ ] `ft_strrchr` - Prototype: `char *ft_strrchr(const char *s, int c);`
  - Parameters:
    - `s`: The string to be scanned.
    - `c`: The character to be searched.
  - Return value: A pointer to the last occurrence of the character `c` in the string `s`, or NULL if the character is not found.
  - Description: Locates the last occurrence of `c` (converted to a char) in the string pointed to by `s`.

- [ ] `ft_strncmp` - Prototype: `int ft_strncmp(const char *s1, const char *s2, size_t n);`
  - Parameters:
    - `s1`: The first string to be compared.
    - `s2`: The second string to be compared.
    - `n`: The maximum number of characters to compare.
  - Return value: An integer less than, equal to, or greater than zero if `s1` is found, respectively, to be less than, to match, or be greater than `s2`.
  - Description: Compares at most the first `n` bytes of the two strings `s1` and `s2`.

- [ ] `ft_memchr` - Prototype: `void *ft_memchr(const void *s, int c, size_t n);`
  - Parameters:
    - `s`: Pointer to the block of memory to be searched.
    - `c`: The value to be searched (interpreted as an unsigned char).
    - `n`: The number of bytes to be analyzed.
  - Return value: A pointer to the matching byte or NULL if the character does not occur in the given memory area.
  - Description: Searches within the first `n` bytes of the memory area pointed to by `s` for the first occurrence of `c`.

- [ ] `ft_memcmp` - Prototype: `int ft_memcmp(const void *s1, const void *s2, size_t n);`
  - Parameters:
    - `s1`: Pointer to the first block of memory.
    - `s2`: Pointer to the second block of memory.
    - `n`: The number of bytes to be compared.
  - Return value: An integer less than, equal to, or greater than zero if the first `n` bytes of `s1` are found to be less than, to match, or be greater than the first `n` bytes of `s2`, respectively.
  - Description: Compares the first `n` bytes of the memory areas `s1` and `s2`.

- [ ] `ft_strnstr` - Prototype: `char *ft_strnstr(const char *haystack, const char *needle, size_t len);`
  - Parameters:
    - `haystack`: The string to be searched.
    - `needle`: The substring to search for.
    - `len`: The maximum number of characters to search.
  - Return value: A pointer to the first character of the first occurrence of `needle` in `haystack`, or NULL if `needle` is not part of `haystack`.
  - Description: Locates the first occurrence of the null-terminated string `needle` in the string `haystack`, where not more than `len` characters are searched.

- [ ] `ft_atoi` - Prototype: `int ft_atoi(const char *str);`
  - Parameters:
    - `str`: The string representation of an integer.
  - Return value: The converted integer value.
  - Description: Converts the initial portion of the string pointed to by `str` to an integer representation.

- [ ] `ft_calloc` - Prototype: `void *ft_calloc(size_t count, size_t size);`
  - Parameters:
    - `count`: The number of elements to allocate.
    - `size`: The size of each element.
  - Return value: A pointer to the allocated memory, or NULL if the allocation fails.
  - Description: Allocates memory for an array of `count` elements of `size` bytes each and returns a pointer to the allocated memory. The memory is set to zero.

- [ ] `ft_strdup` - Prototype: `char *ft_strdup(const char *s1);`
  - Parameters:
    - `s1`: The string to duplicate.
  - Return value: A pointer to the duplicated string, or NULL if insufficient memory was available.
  - Description: Creates a duplicate of the string pointed to by `s1`.

### Part 2 - Additional functions

- [ ] `ft_substr` - Prototype: `char *ft_substr(char const *s, unsigned int start, size_t len);`
  - Parameters:
    - `s`: The string from which to create the substring.
    - `start`: The start index of the substring in the string `s`.
    - `len`: The maximum length of the substring.
  - Return value: The substring. `NULL` if the allocation fails.
  - Description: Allocates (with `malloc(3)`) and returns a substring from the string `s`. The substring begins at index `start` and is of maximum size `len`.

- [ ] `ft_strjoin` - Prototype: `char *ft_strjoin(char const *s1, char const *s2);`
  - Parameters:
    - `s1`: The prefix string.
    - `s2`: The suffix string.
  - Return value: The new string. `NULL` if the allocation fails.
  - Description: Allocates (with `malloc(3)`) and returns a new string, which is the result of the concatenation of `s1` and `s2`.

- [ ] `ft_strtrim` - Prototype: `char *ft_strtrim(char const *s1, char const *set);`
  - Parameters:
    - `s1`: The string to be trimmed.
    - `set`: The reference set of characters to trim.
  - Return value: The trimmed string. `NULL` if the allocation fails.
  - Description: Allocates (with `malloc(3)`) and returns a copy of `s1` with the characters specified in `set` removed from the beginning and the end of the string.

- [ ] `ft_split` - Prototype: `char **ft_split(char const *s, char c);`
  - Parameters:
    - `s`: The string to be split.
    - `c`: The delimiter character.
  - Return value: The array of new strings resulting from the split. `NULL` if the allocation fails.
  - Description: Allocates (with `malloc(3)`) and returns an array of strings obtained by splitting `s` using the character `c` as a delimiter. The array must end with a `NULL` pointer.

- [ ] `ft_itoa` - Prototype: `char *ft_itoa(int n);`
  - Parameters:
    - `n`: The integer to convert.
  - Return value: The string representing the integer. `NULL` if the allocation fails.
  - Description: Allocates (with `malloc(3)`) and returns a string representing the integer received as an argument. Negative numbers must be handled.

- [ ] `ft_strmapi` - Prototype: `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));`
  - Parameters:
    - `s`: The string on which to iterate.
    - `f`: The function to apply to each character.
  - Return value: The string created from the successive applications of `f`. Returns `NULL` if the allocation fails.
  - Description: Applies the function `f` to each character of the string `s`, and passing its index as first argument to create a new string (with `malloc(3)`) resulting from successive applications of `f`.

- [ ] `ft_striteri` - Prototype: `void ft_striteri(char *s, void (*f)(unsigned int, char*));`
  - Parameters:
    - `s`: The string on which to iterate.
    - `f`: The function to apply to each character.
  - Description: Applies the function `f` on each character of the string passed as argument, passing its index as first argument. Each character is passed by address to `f` to be modified if necessary.

- [ ] `ft_putchar_fd` - Prototype: `void ft_putchar_fd(char c, int fd);`
  - Parameters:
    - `c`: The character to output.
    - `fd`: The file descriptor on which to write.
  - Description: Outputs the character `c` to the given file descriptor.

- [ ] `ft_putstr_fd` - Prototype: `void ft_putstr_fd(char *s, int fd);`
  - Parameters:
    - `s`: The string to output.
    - `fd`: The file descriptor on which to write.
  - Description: Outputs the string `s` to the given file descriptor.

- [ ] `ft_putendl_fd` - Prototype: `void ft_putendl_fd(char *s, int fd);`
  - Parameters:
    - `s`: The string to output.
    - `fd`: The file descriptor on which to write.
  - Description: Outputs the string `s` to the given file descriptor followed by a newline.

- [ ] `ft_putnbr_fd` - Prototype: `void ft_putnbr_fd(int n, int fd);`
  - Parameters:
    - `n`: The integer to output.
    - `fd`: The file descriptor on which to write.
  - Description: Outputs the integer `n` to the given file descriptor.

### Bonus Part

- [ ] `ft_lstnew` - Prototype: `t_list *ft_lstnew(void *content);`
  - Parameters:
    - `content`: The content to create the node with.
  - Return value: The new node.
  - Description: Allocates (with `malloc(3)`) and returns a new node. The member variable `content` is initialized with the value of the parameter `content`. The variable `next` is initialized to `NULL`.

- [ ] `ft_lstadd_front` - Prototype: `void ft_lstadd_front(t_list **lst, t_list *new);`
  - Parameters:
    - `lst`: The address of a pointer to the first link of a list.
    - `new`: The address of a pointer to the node to be added to the list.
  - Description: Adds the node `new` at the beginning of the list.

- [ ] `ft_lstsize` - Prototype: `int ft_lstsize(t_list *lst);`
  - Parameters:
    - `lst`: The beginning of the list.
  - Return value: The length of the list.
  - Description: Counts the number of nodes in a list.

- [ ] `ft_lstlast` - Prototype: `t_list *ft_lstlast(t_list *lst);`
  - Parameters:
    - `lst`: The beginning of the list.
  - Return value: Last node of the list.
  - Description: Returns the last node of the list.

- [ ] `ft_lstadd_back` - Prototype: `void ft_lstadd_back(t_list **lst, t_list *new);`
  - Parameters:
    - `lst`: The address of a pointer to the first link of a list.
    - `new`: The address of a pointer to the node to be added to the list.
  - Description: Adds the node `new` at the end of the list.

- [ ] `ft_lstdelone` - Prototype: `void ft_lstdelone(t_list *lst, void (*del)(void *));`
  - Parameters:
    - `lst`: The node to free.
    - `del`: The address of the function used to delete the content.
  - Description: Takes as a parameter a node and frees the memory of the node's content using the function `del` given as a parameter and free the node. The memory of `next` must not be freed.

- [ ] `ft_lstclear` - Prototype: `void ft_lstclear(t_list **lst, void (*del)(void *));`
  - Parameters:
    - `lst`: The address of a pointer to a node.
    - `del`: The address of the function used to delete the content of the node.
  - Description: Deletes and frees the given node and every successor of that node, using the function `del` and `free(3)`. Finally, the pointer to the list must be set to `NULL`.

- [ ] `ft_lstiter` - Prototype: `void ft_lstiter(t_list *lst, void (*f)(void *));`
  - Parameters:
  - `new`: The address of a pointer to the node to be added to the list.
- Description: Adds the node `new` at the beginning of the list.

- [ ] `ft_lstsize` - Prototype: `int ft_lstsize(t_list *lst);`
  - Parameters:
    - `lst`: The beginning of the list.
  - Return value: The length of the list.
  - Description: Counts the number of nodes in a list.

- [ ] `ft_lstlast` - Prototype: `t_list *ft_lstlast(t_list *lst);`
  - Parameters:
    - `lst`: The beginning of the list.
  - Return value: Last node of the list.
  - Description: Returns the last node of the list.

- [ ] `ft_lstadd_back` - Prototype: `void ft_lstadd_back(t_list **lst, t_list *new);`
  - Parameters:
    - `lst`: The address of a pointer to the first link of a list.
    - `new`: The address of a pointer to the node to be added to the list.
  - Description: Adds the node `new` at the end of the list.

- [ ] `ft_lstdelone` - Prototype: `void ft_lstdelone(t_list *lst, void (*del)(void *));`
  - Parameters:
    - `lst`: The node to free.
    - `del`: The address of the function used to delete the content.
  - Description: Takes as a parameter a node and frees the memory of the node's content using the function `del` given as a parameter and free the node. The memory of `next` must not be freed.

- [ ] `ft_lstclear` - Prototype: `void ft_lstclear(t_list **lst, void (*del)(void *));`
  - Parameters:
    - `lst`: The address of a pointer to a node.
    - `del`: The address of the function used to delete the content of the node.
  - Description: Deletes and frees the given node and every successor of that node, using the function `del` and `free(3)`. Finally, the pointer to the list must be set to `NULL`.

- [ ] `ft_lstiter` - Prototype: `void ft_lstiter(t_list *lst, void (*f)(void *));`
  - Parameters:
    - `lst`: The address of a pointer to a node.
    - `f`: The address of the function used to iterate on the list.
  - Description: Iterates the list `lst` and applies the function `f` on the content of each node.

- [ ] `ft_lstmap` - Prototype: `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));`
  - Parameters:
    - `lst`: The address of a pointer to a node.
    - `f`: The address of the function used to iterate on the list.
    - `del`: The address of the function used to delete the content of a node if needed.
  - Return value: The new list. `NULL` if the allocation fails.
