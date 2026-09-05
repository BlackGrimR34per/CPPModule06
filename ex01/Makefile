# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08 18:08:47 by yosherau          #+#    #+#              #
#    Updated: 2026/09/05 15:32:37 by yosherau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		c++

FLAGS		=		-Wall -Wextra -Werror -std=c++98

NAME		=		Serializer

SRCS_DIR	=		./srcs

SRCS		=		$(wildcard $(SRCS_DIR)/*.cpp)

OBJS_DIR	=		./objs

OBJS		=		$(patsubst $(SRCS_DIR)/%.cpp, $(OBJS_DIR)/%.o, $(SRCS))

RM			=		rm -rf

all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.cpp | $(OBJS_DIR)
					$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR):
					mkdir -p $(OBJS_DIR)

clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all