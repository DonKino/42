#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jburet <jburet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 14:48:56 by jburet            #+#    #+#              #
#    Updated: 2013/11/20 14:48:59 by jburet           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -Wall -Wextra -Werror

FIC_C = main.c \
		ft_ls_stat.c \
		ls_print.c \
		ls_args.c \

FIC_O =  main.o \
		ft_ls_stat.o\
		ls_print.o \
		ls_args.o \

HEADER = -I./ -I$(DIR_LIB)

NAME = ft_ls

DIR_LIB = ./lib/

LIB = cd $(DIR_LIB)

all: $(NAME)

$(NAME):
	$(LIB); make
	gcc -o $(NAME) $(FIC_C) -L$(DIR_LIB) -lft $(HEADER) $(FLAGS)

clean:
	$(LIB); make clean
	rm -f $(FIC_O)

fclean: clean
	rm -f $(NAME)

re: fclean all
