# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:11:28 by eozdek            #+#    #+#              #
#    Updated: 2016/03/28 23:45:51 by eozdek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in
FILES	= main.c ft_rest.c ft_check.c ft_error.c ft_graphe.c ft_list.c \
	ft_algo.c print_lem.c ft_check_2.c ft_check_3.c print_lem_2.c \
	ft_check_4.c get_next_line.c ft_check_5.c
SRCS	= $(addprefix src/, $(FILES))
OBJS	= $(SRCS:src/%.c=.obj/%.o)
INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft
CC		= gcc

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[95m	__    ____  __  __     ____  _  _ "
	@echo "\033[95m       (  )  ( ___)(  \/  )___(_  _)( \( )"
	@echo "\033[95m        )(__  )__)  )    ((___)_)(_  )  ( "
	@echo "\033[95m       (____)(____)(_/\/\_)   (____)(_)\_)"
	@echo "\033[96m                  by e🏀 zdek\033[97m         "
	@echo "\033[91mCompiling 😇\033[97m"
		@make -C libft
		@$(CC) $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB)
		@echo "\033[90mDone 😎\033[97m"
.obj/%.o: src/%.c
	mkdir -p .obj
	@$(CC) -c $< -o $@ $(FLAGS) $(INC)

clean:
	@echo "\033[92mDeleting 💀\033[97m"
	@rm -rf .obj
	@make clean -C libft
	@echo "\033[96mClean done 😡\033[97m"

fclean: clean
	@echo "\033[92mDeleting 💀\033[97m"
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "\033[96mFclean Done 👿\033[97m"

re: fclean all

.PHONY: all clean fclean re
