NAME = so_long

SRCS = 	srcs/main.c srcs/background.c srcs/events.c srcs/events_helper.c\
		parsing/parsing.c parsing/parsing_helper.c parsing/checks_args.c\
		libft/ft_strchr.c libft/ft_putstr_fd.c libft/ft_putnbr_fd.c libft/ft_putchar_fd.c\
		gnl/get_next_line.c gnl/get_next_line_utils.c\
		ft_printf/ft_printf.c ft_printf/ft_print_char.c ft_printf/ft_print_hexa.c ft_printf/ft_print_integers.c\
		ft_printf/ft_print_pointer.c ft_printf/ft_print_str.c ft_printf/ft_print_unsintegers.c ft_printf/ft_print_upper_hexa.c ft_printf/ft_putchar.c\

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

all:	${NAME}

C_O = \
    if [ ! -e  "objs" ]; then \
    mkdir objs; \
    fi

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): ${OBJS}
		$(CC) ${CFLAGS} $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
		@$(C_O)
		@mv $(OBJS) objs/

clean:
		${RM} ${OBJS}
		@rm -rf objs\

fclean:	clean
		${RM} ${NAME}

re:		fclean all

PHONY:	re flcean clean all
