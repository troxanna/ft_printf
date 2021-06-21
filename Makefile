NAME = libftprintf.a

SRCS_PATH = ./

LIBFT_PATH = libft/

LIBFT_LIB = libft.a

HEADERS_FOLDER = ./

SRCS_FILES = ft_parser.c print_char.c print_string.c print_hex.c \
		print_int.c print_u_int.c print_pointer.c ft_printf.c utils.c

SRCS_OBJS = ${SRCS_FILES:.c=.o}

CC = gcc

CFLAGS = -Wall 

RM = rm -f

AR = ar crs

LIBFT_OBJS = ${LIBFT_PATH}*.o

LIBFTMAKE = $(MAKE) -C ${LIBFT_PATH}

all: ${NAME}

${NAME}: ${SRCS_OBJS} pmake
		${AR} ${NAME} ${SRCS_OBJS} ${LIBFT_OBJS}

pmake:
		${LIBFTMAKE}

clean:
	make -C ${LIBFT_PATH} clean
			${RM} ${SRCS_OBJS}

fclean: clean
		${RM} ${NAME} ${LIBFT_PATH}${LIBFT_LIB}

re: fclean all

.PHONY: all clean fclean re