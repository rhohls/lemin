# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 13:08:28 by rhohls            #+#    #+#              #
#    Updated: 2018/08/30 10:04:38 by rhohls           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
TEST ?= test.c

# Path
SRC_PATH = ./src/
OBJ_PATH = ./objs/
INC_PATH = ./includes/
LIB_PATH = ./libft/

# Files
SRC_FILE =	add_connection.c	\
			add_room.c		\
			data_collection.c	\
			data_free.c		\
			ft_strin.c		\
			inits.c			\
			path_bool.c		\
			pathing.c		\
			pathing_func.c	\
			print_moves.c	\
			stack_functions.c	\
			ant_moves.c		\
	

OBJ_FILE = $(SRC_FILE:%.c=%.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILE))

CHECK_MAIN = ./src_check/checker.c
NAME_MAIN = ./src_lemin/lemin.c

#Compile
CCFLAGS = -Wall -Werror -Wextra
CC = gcc $(CCFLAGS)

LIBF = $(LIB_PATH)libft.a

#Make Commands
all: $(NAME)

$(NAME): $(OBJ) $(NAME_MAIN)
	@make -C./libft/
	@$(CC)  -o $@ $(LIBF) $(OBJ) $(NAME_MAIN)
	@echo "\x1b[32m"Finished making $@"\x1b[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) -I$(INC_PATH) -o $@ -c $<
	@echo Making "\x1b[35m"$@"\x1b[0m"

test: $(OBJ) $(TEST)
	@make -C./libft/
	@$(CC) -o $@ $(OBJ) $(TEST) $(LIBF)

clean: 
	@/bin/rm -rf $(OBJ)
	@echo "\x1b[31m"Removed all $(NAME) objects"\x1b[0m"

fclean: clean 
	@rm -f $(NAME)
	@echo "\x1b[31m"Removed $(NAME)"\x1b[0m"
	
cleanall: fclean fcleanlib

cleanlib:
	@make clean -C $(LIB_PATH)

fcleanlib:
	@make fclean -C $(LIB_PATH)

re : cleanall all

.PHONY: re fclean clean all
