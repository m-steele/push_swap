# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 09:57:19 by ekosnick          #+#    #+#              #
#    Updated: 2024/11/25 15:01:18 by peatjohnsto      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#compliler and flags
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

#source 'c' and object 'o' files
SRCS =	toy.c \
		../libft/process_xx.c \
		../libft/process_x.c	\
		../libft/process_u.c \
		../libft/process_s.c \
		../libft/process_p.c \
		../libft/process_id.c \
		../libft/process_c.c \
		../libft/ft_printf.c \
		../libft/ft_lstnew.c \
		../libft/ft_lstadd_front.c \
		../libft/ft_lstsize.c \
		../libft/ft_lstlast.c \
		../libft/ft_lstadd_back.c \
		../libft/ft_lstdelone.c \
		../libft/ft_lstclear.c \
		../libft/ft_lstiter.c \
		../libft/ft_lstmap.c \

OBJ = $(SRCS:.c=.o)

NAME = pushtoy.a

#converts .c files --> .o files in libft.h directory: (-o $@ -->id .o names) ($< --> first rerequisite .c names)
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@ 

#creates the library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

#Rules
all: $(NAME)

clean:
	$(RM) $(OBJ) program a.out

fclean: clean
	$(RM) $(NAME)

re:	fclean all

#Do not confuse files with these rules
.PHONY: re all clean fclean