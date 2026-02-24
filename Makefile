# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adzmusta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 00:15:04 by adzmusta          #+#    #+#              #
#    Updated: 2026/02/24 15:44:29 by adzmusta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       parse.c \
       error.c \
       error_utils.c \
       stack.c \
       stack_utils.c \
       index.c \
       sort_small.c \
       sort_big.c \
       push.c \
       swap.c \
       rotate.c \
       reverse_rotate.c \
       utils.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all = $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
