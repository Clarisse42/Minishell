# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/06 06:09:24 by ccharuel          #+#    #+#              #
#    Updated: 2017/05/09 11:46:51 by ccharuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

DIR_LIB = "libft"
DIR_SRC = "src"
DIR_INC = "include"

SRC = $(shell find $(DIR_SRC) -type f | grep "\.c") 
OBJ = $(SRC:%.c=%.o)

INC = -I $(DIR_INC)
INC += -I $(DIR_LIB)/$(DIR_INC)

FLAG = -g -O0 -Wall -Wextra -Werror #-fsanitize=address


PRINT = printf "\033[34m%-25s\033[0m\t-->>\t\033[31;1m%-40s\033[0m\n"

all: $(NAME)

$(NAME): $(OBJ)
		@make -C $(DIR_LIB)
			@gcc $(FLAG) $(INC) -L $(DIR_LIB) -lft -o $@ $(OBJ)
				@$(PRINT) "src" $(NAME)

%.o: %.c
		@$(PRINT) $@ $<
			@gcc $(FLAG) $(INC) -o $@ -c $<

clean:
		@make -C $(DIR_LIB) clean
			@rm -rf $(OBJ)

fclean : clean
		@make -C $(DIR_LIB) fclean
			@rm -rf $(NAME)

re : fclean all

.PHONY: re all clean fclean

