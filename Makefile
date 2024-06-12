# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 10:56:21 by ahusic            #+#    #+#              #
#    Updated: 2024/06/05 17:40:21 by ahusic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

SRCS = main.c error_handle.c operations.c operations2.c operations3.c \
		parsing.c prep_pa.c prep_pb.c sorting.c utils.c utils2.c

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

INCLUDE = -L $(LIBFT_PATH) -lft

all: $(NAME)

.SILENT:

	@echo "Compiling $<"
$(NAME): $(LIBFT) $(OBJS)
	@cc $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJS) $(INCLUDE)
	@echo "push_swap compiled"

$(LIBFT):
	@make -C $(LIBFT_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "push_swap cleaned"

re: fclean all

.PHONY: all clean fclean re
