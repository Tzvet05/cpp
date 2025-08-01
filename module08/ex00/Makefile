# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttrave <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 17:44:05 by ttrave            #+#    #+#              #
#    Updated: 2024/11/28 18:41:40 by ttrave           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Make parameters

NAME =		easyfind

COMPILER =	c++

CFLAG =		-Wall -Wextra -Werror -std=c++98

# Directories

COLOR_DEFAULT =	\033[0m
COLOR_GREEN =	\033[1;38;5;2m
COLOR_BLUE =	\033[1;38;5;4m
COLOR_WHITE =	\033[1;38;5m

# Source code (mandatory)

SRC =	main.cpp

# Compiled objects (mandatory)

OBJ = $(SRC:.cpp=.o)

# Compilation (mandatory)

$(NAME) : $(OBJ)
	@ echo "$(COLOR_WHITE)[$(NAME)] - $(COLOR_GREEN)Executable ($(NAME)) compiled (mandatory).$(COLOR_DEFAULT)"
	@ $(COMPILER) $(CFLAG) $(OBJ) -o $(NAME)

%.o : %.cpp
	@ $(COMPILER) $(CFLAG) -c $^ -o $@

# Rules

all : $(NAME)

fclean :
	@ echo "$(COLOR_WHITE)[$(NAME)] - $(COLOR_BLUE)Executable ($(NAME)) cleaned.$(COLOR_DEFAULT)\n$(COLOR_WHITE)[$(NAME)] - $(COLOR_BLUE)Objects cleaned.$(COLOR_DEFAULT)"
	@ rm -rf $(NAME) $(OBJ)

clean :
	@ echo "$(COLOR_WHITE)[$(NAME)] - $(COLOR_BLUE)Objects cleaned.$(COLOR_DEFAULT)"
	@ rm -rf $(OBJ)

re : fclean all

.PHONY: all clean fclean re
