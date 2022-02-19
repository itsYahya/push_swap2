# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 13:22:30 by yel-mrab          #+#    #+#              #
#    Updated: 2022/02/18 15:40:50 by yel-mrab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GWC = cc -Wall -Wextra -Werror -g
NAME = push_swap
B_NAME = bonus_checker

M_SRC = src/main.c src/main_utils.c src/moves.c src/moves_2.c src/sort.c src/sort_utils.c src/basic_sort.c
B_SRC = checker_bonus/main.c checker_bonus/main_utils.c checker_bonus/moves.c checker_bonus/moves_2.c \
		checker_bonus/check.c checker_bonus/ft_strncmp.c checker_bonus/get_next_line_utils.c checker_bonus/get_next_line.c

M_OBJ = $(M_SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(M_OBJ)
	$(GWC) $(M_OBJ) -o $(NAME)

bonus : $(B_NAME)

$(B_NAME) : $(B_OBJ)
	$(GWC) $(B_OBJ) -o $(B_NAME)

%.o : %.c
	$(GWC) -c $< -o $@

clean : 
	rm -rf $(B_OBJ)
	rm -rf $(M_OBJ)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(B_NAME)

re : fclean all

.PHONY : re fclean clean all bonus
