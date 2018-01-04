# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/04 13:53:13 by ccharuel          #+#    #+#              #
#    Updated: 2017/05/09 11:47:16 by ccharuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

DIR_SRC = "src"
DIR_INC = "include"

SRC = $(shell find $(DIR_SRC) -type f | grep "\.c") 
OBJ = $(SRC:%.c=%.o)

INC = -I $(DIR_INC)

FLAG = -Wall -Wextra -Werror

PRINT = printf "\033[34m%-25s\033[0m\t-->>\t\033[31;1m%-40s\033[0m\n"

all : $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	$(PRINT) "src" $(NAME)

%.o: %.c
	$(PRINT) $@ $<
	gcc $(FLAG) $(INC) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: re all clean fclean $(NAME)
.SILENT:
