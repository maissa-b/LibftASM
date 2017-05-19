# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/24 15:20:46 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 17:50:11 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a

SRC = ft_bzero.s ft_strcat.s ft_isalpha.s ft_isdigit.s ft_isalnum.s \
		ft_isascii.s ft_isprint.s ft_toupper.s ft_tolower.s ft_puts.s\
		ft_strlen.s ft_memset.s ft_memcpy.s ft_strdup.s ft_isupper.s \
		ft_islower.s ft_cat.s ft_isxdigit.s ft_isspace.s ft_isblank.s \
		ft_strcpy.s ft_strncpy.s ft_putstring.s ft_strnew.s ft_memalloc.s


OBJ = $(SRC:.s=.o)

all: $(NAME)

main:
	gcc -Wall -Werror -Wextra main.c libfts.a

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "\033[32mCompilation done.\033[0m"
		@echo "\033[36m////////////////////////////////////////////////////////////\033[m"

%.o: %.s
		@nasm -f macho64 $< -o $@

clean:
	@rm -rf $(OBJ)
	@echo "\033[31mSupression des .o.\033[m"
	@echo "\033[36m////////////////////////////////////////////////////////////\033[m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mSuppression du .a.\033[m"
	@echo "\033[36m////////////////////////////////////////////////////////////\033[m"

re: fclean all

exec: re main
	@./a.out
