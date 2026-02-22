# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adzmusta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 00:15:04 by adzmusta          #+#    #+#              #
#    Updated: 2026/02/23 00:23:55 by adzmusta         ###   ########.fr        #
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

all = $(NAME)
