NAME = libftprintf.a

SRCS =	ft_printf.c ft_printer.c

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):$(OBJS)
	ar -crs $(NAME) $(OBJS) 

%.o:%.c ft_printf.h
	cc $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re