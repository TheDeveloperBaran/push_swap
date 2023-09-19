# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bakilic <bakilic@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 20:16:39 by bakilic           #+#    #+#              #
#    Updated: 2023/07/06 20:25:42 by bakilic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FRAEMWORKS = -framework OpenGL -framework AppKit -g
FLAGS = -Wall -Wextra -Werror
SRC = push_swap.c \
	ft_split.c \
	ft_atoi.c \
	ft_isdigit.c \
	ft_strlen.c \
	control.c \
	swap_s.c \
	swap.c \
	swap_reverse.c \
	push.c \
	sorting.c \
	sort_partone.c \
	sort_partwo.c \
	radix.c \
	



	

GREEN := \033[1;32m
RED := \033[1;41m
END := \033[0;39m

OBJ = $(SRC:.c=.o)

INCLUDES = mlx/libmlx.a

all: $(OBJ)
	@gcc $(SRC) -o $(NAME) $(FLAGS) $(FRAEMWORKS)
	@echo "$(GREEN)Compile Completed!$(END)"

clean:
	rm -rf $(OBJ)
	@echo "$(RED)Cleaning Completed!$(END)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
