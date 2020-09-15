# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/05 19:21:13 by suntlee           #+#    #+#              #
#    Updated: 2020/09/15 15:36:24 by suntlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
LIBFT = libft
DIR_S = srcs
DIR_O = obj

HEADER = includes

SOURCES = ft_printf.c parse.c print_nb.c print_str.c print_pointer.c print_padding.c parse_utils.c print_percent.c

SRCS = $(addprefix $(DIR_S)/, $(SOURCES))

OBJS = $(addprefix $(DIR_O)/, $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	mkdir -p obj
	$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -rf $(DIR_O)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

bonus: all

.PHONY: fclean re norme all clean
