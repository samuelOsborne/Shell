##
## Makefile for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
## 
## Made by Lucas Villeneuve
## Login   <villen_l@epitech.net>
## 
## Started on  Wed May 11 16:00:21 2016 Lucas Villeneuve
## Last update Wed May 11 16:47:17 2016 Lucas Villeneuve
##

NAME	=	42sh

SRC	=	src/main.c		\
		src/get_next_line.c	\
		src/my_str_to_wordtab.c	\
		src/my_print.c		\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

RM	=	rm -rf

CFLAGS	=	-I include -W -Wall -Wextra

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
