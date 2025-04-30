# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 09:57:19 by ekosnick          #+#    #+#              #
#    Updated: 2025/04/30 12:21:54 by ekosnick         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#compliler and flags
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

#source 'c' and object 'o' files takes them from libft folder!!!
SRCS =	../libft/process_xx.c ../libft/process_x.c	\
		../libft/process_u.c ../libft/process_s.c \
		../libft/process_p.c ../libft/process_id.c \
		../libft/process_c.c ../libft/ft_printf.c \
		../libft/ft_lstnew.c ../libft/ft_lstadd_front.c \
		../libft/ft_lstsize.c ../libft/ft_lstlast.c \
		../libft/ft_lstadd_back.c ../libft/ft_lstdelone.c \
		../libft/ft_lstclear.c ../libft/ft_lstiter.c \
		../libft/ft_lstmap.c ../libft/ft_atoi.c \
		../libft/ft_itoa.c ../libft/ft_strdup.c \
		../libft/ft_strjoin.c ../libft/ft_strlen.c \
		../libft/ft_isdigit.c ../libft/ft_split.c \
		../libft/ft_strchr.c ../libft/ft_abs.c \
		push_swap.c not_valid.c start_sort.c \
		swap.c rotate.c reverse.c push.c find_n_smallest.c \
		find_n_biggest.c utilities.c moveit.c \

# push_ops.c
OBJ = $(SRCS:.c=.o)

NAME = push_swap

#converts .c files --> .o files: (-o $@ -->id .o names) ($< --> first rerequisite .c names)
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@ 

#creates the library
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
# ar rcs $(NAME) $(OBJ)

libft:
	$(MAKE) -C ../libft

#Rules
all: $(NAME)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C ../libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ../libft fclean

re:	fclean all

#Do not confuse files with these rules
.PHONY: re all clean fclean