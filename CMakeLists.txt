cmake_minimum_required(VERSION 3.15)
project(minishell C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell main.c
        ./sources/libft/src/io/ft_printf/src/ft_printf.c
        ./sources/libft/src/io/ft_printf/src/pf_count.c
        ./sources/libft/src/io/ft_printf/src/pf_getarg.c
        ./sources/libft/src/io/ft_printf/src/pf_getdignum.c
        ./sources/libft/src/io/ft_printf/src/pf_isflag.c
        ./sources/libft/src/io/ft_printf/src/pf_istype.c
        ./sources/libft/src/io/ft_printf/src/pf_lcadd_back.c
        ./sources/libft/src/io/ft_printf/src/pf_lcclear.c
        ./sources/libft/src/io/ft_printf/src/pf_lcnew.c
        ./sources/libft/src/io/ft_printf/src/pf_lcprint_n_clear.c
        ./sources/libft/src/io/ft_printf/src/pf_order.c
        ./sources/libft/src/io/ft_printf/src/pf_parse.c
        ./sources/libft/src/io/ft_printf/src/pf_puthex.c
        ./sources/libft/src/io/ft_printf/src/pf_putint.c
        ./sources/libft/src/io/ft_printf/src/pf_putnbr.c
        ./sources/libft/src/io/ft_printf/src/pf_putprec.c
        ./sources/libft/src/io/ft_printf/src/pf_putprefix.c
        ./sources/libft/src/io/ft_printf/src/pf_putstr.c
        ./sources/libft/src/io/ft_printf/src/pf_putwidth.c
        ./sources/libft/src/io/ft_printf/src/pf_write_data.c
        ./sources/libft/src/io/ft_putchar.c
        ./sources/libft/src/io/ft_putchar_fd.c
        ./sources/libft/src/io/ft_putendl_fd.c
        ./sources/libft/src/io/ft_putnbr.c
        ./sources/libft/src/io/ft_putnbr_fd.c
        ./sources/libft/src/io/ft_putnbr_unsigned.c
        ./sources/libft/src/io/ft_putstr.c
        ./sources/libft/src/io/ft_putstr_fd.c
        ./sources/libft/src/io/gnl/get_next_line.c
        ./sources/libft/src/io/gnl/get_next_line_utils.c
        ./sources/libft/src/lst/ft_lstadd_back.c
        ./sources/libft/src/lst/ft_lstadd_front.c
        ./sources/libft/src/lst/ft_lstclear.c
        ./sources/libft/src/lst/ft_lstdelone.c
        ./sources/libft/src/lst/ft_lstiter.c
        ./sources/libft/src/lst/ft_lstlast.c
        ./sources/libft/src/lst/ft_lstmap.c
        ./sources/libft/src/lst/ft_lstnew.c
        ./sources/libft/src/lst/ft_lstsize.c
        ./sources/libft/src/std/ft_atoi.c
        ./sources/libft/src/std/ft_calloc.c
        ./sources/libft/src/std/ft_itoa.c
        ./sources/libft/src/string/ft_bzero.c
        ./sources/libft/src/string/ft_memccpy.c
        ./sources/libft/src/string/ft_memchr.c
        ./sources/libft/src/string/ft_memcmp.c
        ./sources/libft/src/string/ft_memcpy.c
        ./sources/libft/src/string/ft_memmove.c
        ./sources/libft/src/string/ft_memset.c
        ./sources/libft/src/string/ft_split.c
        ./sources/libft/src/string/ft_strchr.c
        ./sources/libft/src/string/ft_strdup.c
        ./sources/libft/src/string/ft_strjoin.c
        ./sources/libft/src/string/ft_strlcat.c
        ./sources/libft/src/string/ft_strlcpy.c
        ./sources/libft/src/string/ft_strlen.c
        ./sources/libft/src/string/ft_strmapi.c
        ./sources/libft/src/string/ft_strncmp.c
        ./sources/libft/src/string/ft_strnstr.c
        ./sources/libft/src/string/ft_strrchr.c
        ./sources/libft/src/string/ft_strtrim.c
        ./sources/libft/src/string/ft_substr.c
        ./sources/libft/src/types/ft_isalnum.c
        ./sources/libft/src/types/ft_isalpha.c
        ./sources/libft/src/types/ft_isascii.c
        ./sources/libft/src/types/ft_isdigit.c
        ./sources/libft/src/types/ft_islower.c
        ./sources/libft/src/types/ft_isprint.c
        ./sources/libft/src/types/ft_isspace.c
        ./sources/libft/src/types/ft_isupper.c
        ./sources/libft/src/types/ft_tolower.c
        ./sources/libft/src/types/ft_toupper.c
        includes/utils.h sources/utils/ls_append.c sources/utils/ls_to_string.c sources/utils/ls_length.c sources/parser/handle_general_state.c sources/parser/handle_in_string_state.c sources/parser/handle_in_semicolon_state.c sources/parser/handle_in_pipe_state.c sources/parser/handle_in_ampresand_state.c sources/parser/handle_in_or_state.c sources/parser/handle_in_and_state.c sources/parser/handle_in_single_quotes_state.c sources/parser/handle_in_double_quotes_state.c sources/parser/handle_in_backslash_state.c sources/parser/handle_initial_state.c sources/parser/append_token.c includes/parser.h sources/parser/handle_in_greater_state.c sources/parser/handle_in_redir_input_state.c sources/parser/handle_in_redir_output_state.c)

include_directories(includes sources/libft/inc)