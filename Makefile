# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heljary <heljary@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 09:33:40 by heljary           #+#    #+#              #
#    Updated: 2024/12/02 17:15:36 by heljary          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftgetnextline.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c

# BONUS = ft_lstnew_bonus.c \

OBJ = $(SRC:.c=.o)
# BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# bonus: $(OBJ) $(BONUS_OBJ)
# 	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
