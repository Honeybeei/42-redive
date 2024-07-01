pub mod libft {
    // ft_isalpha
    pub fn is_alpha(c: char) -> bool {
        if (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') {
            return true;
        }
        false
    }

    // ft_isdigit
    pub fn is_digit(c: char) -> bool {
        if c >= '0' && c <= '9' {
            return true;
        }
        false
    }

    // ft_isalnum
    pub fn is_alnum(c: char) -> bool {
        if is_alpha(c) || is_digit(c) {
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
        assert_eq!(is_alpha('a'), true);
        assert_eq!(is_alpha('z'), true);
        assert_eq!(is_alpha('A'), true);
        assert_eq!(is_alpha('Z'), true);
        assert_eq!(is_alpha('0'), false);
        assert_eq!(is_alpha('9'), false);
        assert_eq!(is_alpha(' '), false);
    }

    #[test]
    fn test_is_digit() {
        assert_eq!(is_digit('a'), false);
        assert_eq!(is_digit('z'), false);
        assert_eq!(is_digit('A'), false);
        assert_eq!(is_digit('Z'), false);
        assert_eq!(is_digit('0'), true);
        assert_eq!(is_digit('9'), true);
        assert_eq!(is_digit(' '), false);
    }

    #[test]
    fn test_is_alnum() {
        assert_eq!(is_alnum('a'), true);
        assert_eq!(is_alnum('z'), true);
        assert_eq!(is_alnum('A'), true);
        assert_eq!(is_alnum('Z'), true);
        assert_eq!(is_alnum('0'), true);
        assert_eq!(is_alnum('9'), true);
        assert_eq!(is_alnum(' '), false);
    }
}
