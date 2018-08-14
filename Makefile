# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhohls <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 13:08:28 by rhohls            #+#    #+#              #
#    Updated: 2018/07/17 13:12:15 by rhohls           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK = checker
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
			generate_paths.c	\
			inits.c			\
			path_bool.c		\
			pathing.c		\
			pathing_func.c	\
			print.c			\
			stack_functions.c	\
	

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
all: $(CHECK) $(NAME)

$(CHECK): $(OBJ) $(CHECK_MAIN)
	@make -C./libft/
	@$(CC) -o $@ $(LIBF) $(OBJ) $(CHECK_MAIN) 

$(NAME): $(OBJ) $(NAME_MAIN)
	@make -C./libft/
	@$(CC)  -o $@ $(LIBF) $(OBJ) $(NAME_MAIN)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) -I$(INC_PATH) -o $@ -c $<

test: $(OBJ)  $(TEST)
	@make -C./libft/
	@$(CC) -o $@ $(OBJ) $(TEST) $(LIBF)

clean: cleanlib
	/bin/rm -rf $(OBJ)

fclean: clean fcleanlib
	@rm -f $(CHECK)
	@rm -f $(NAME)

cleanlib:
	@make clean -C $(LIB_PATH)

fcleanlib:
	@make fclean -C $(LIB_PATH)

re : fclean all

.PHONY: re fclean clean all
