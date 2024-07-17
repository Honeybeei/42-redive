pub mod libft {
    // ft_isalpha
    pub fn ft_isalpha(c: char) -> bool {
        if (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') {
            return true;
        }
        false
    }

    // ft_isdigit
    pub fn ft_isdigit(c: char) -> bool {
        if c >= '0' && c <= '9' {
            return true;
        }
        false
    }

    // ft_isalnum
    pub fn ft_isalnum(c: char) -> bool {
        if ft_isalpha(c) || ft_isdigit(c) {
            return true;
        }
        false
    }

    // ft_isascii
    pub fn ft_isascii(c: char) -> bool {
        if c >= '\0' && c <= '\x7F' {
            return true;
        }
        false
    }

    // ft_isprint
    pub fn ft_isprint(c: char) -> bool {
        if c >= ' ' && c <= '~' {
            return true;
        }
        false
    }
}

#[cfg(test)]
mod tests {
    use super::libft::*;

    #[test]
    fn test_is_alpha() {
        assert_eq!(ft_isalpha('a'), true);
        assert_eq!(ft_isalpha('z'), true);
        assert_eq!(ft_isalpha('A'), true);
        assert_eq!(ft_isalpha('Z'), true);
        assert_eq!(ft_isalpha('0'), false);
        assert_eq!(ft_isalpha('9'), false);
        assert_eq!(ft_isalpha(' '), false);
    }

    #[test]
    fn test_is_digit() {
        assert_eq!(ft_isdigit('a'), false);
        assert_eq!(ft_isdigit('z'), false);
        assert_eq!(ft_isdigit('A'), false);
        assert_eq!(ft_isdigit('Z'), false);
        assert_eq!(ft_isdigit('0'), true);
        assert_eq!(ft_isdigit('9'), true);
        assert_eq!(ft_isdigit(' '), false);
    }

    #[test]
    fn test_is_alnum() {
        assert_eq!(ft_isalnum('a'), true);
        assert_eq!(ft_isalnum('z'), true);
        assert_eq!(ft_isalnum('A'), true);
        assert_eq!(ft_isalnum('Z'), true);
        assert_eq!(ft_isalnum('0'), true);
        assert_eq!(ft_isalnum('9'), true);
        assert_eq!(ft_isalnum(' '), false);
    }

    #[test]
    fn test_is_ascii() {
        // check for ascii characters
        assert_eq!(ft_isascii('\0'), true);
        assert_eq!(ft_isascii('\x7F'), true);
        // check for non-ascii characters
        assert_eq!(ft_isascii('😀'), false);
    }

    #[test]
    fn test_is_print() {
        // check for printable characters
        assert_eq!(ft_isprint(' '), true);
        assert_eq!(ft_isprint('~'), true);
        // check for non-printable characters
        assert_eq!(ft_isprint('\0'), false);
        assert_eq!(ft_isprint('\x7F'), false);
    }
}
