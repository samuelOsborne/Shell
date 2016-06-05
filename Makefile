##
## Makefile for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
##
## Made by Lucas Villeneuve
## Login   <villen_l@epitech.net>
##
## Started on  Wed May 11 16:00:21 2016 Lucas Villeneuve
## Last update Sun Jun  5 14:59:55 2016 Lucas Villeneuve
##

NAME	=	42sh

SRC	=	main.c			\
		get_next_line.c		\
		my_str_to_wordtab.c	\
		my_str_to_wordpipe.c	\
		my_print.c		\
		error.c			\
		my_free.c		\
		epurstr.c		\
		my_env.c		\
		create_tree.c		\
		my_exec.c		\
		my_getenv.c		\
		find_type_cmd.c		\
		builtins.c		\
		my_exit.c		\
		my_getnbr.c		\
		manage_tab_env.c	\
		my_echo.c		\
		my_echo_dollar.c	\
		my_cd.c			\
		my_pipe.c		\
		create_cmd_pipe.c	\
		exec_pipe.c		\
		manage_pipe.c		\
		check_pipe.c		\
		count_wordpipe.c	\
		loop_pipe.c		\
		command_not_found.c	\
		get_spec.c		\
		exec_tree.c		\
		alias_list.c		\
		init_rc.c		\
		merge_alias.c		\
		globbing.c		\
		prompt.c		\
		preparsing.c		\
		alphanum.c

OBJ	=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

OBJDIR	=	obj/

SRCDIR =        src/

CC	=	gcc

RM	=	rm -rf

MK	=	mkdir

CFLAGS	=	-I include -W -Wall -Wextra

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

$(OBJDIR)%.o:   $(SRCDIR)%.c
		@$(MK) -p $(OBJDIR)
		$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		$(RM) -r $(OBJDIR)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
