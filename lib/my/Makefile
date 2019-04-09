##
## EPITECH PROJECT, 2018
## Makefile
## File description:
##
##

SRC	=	my_itoa.c	\
		my_towordtab.c	\
		my_getnbr.c	\
		my_putchar.c	\
		my_getfile.c	\
		my_revstr.c	\
		my_count.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strlen.c	\
		my_strncpy.c	\
		my_strncmp.c	\
		my_strncat.c	\
		my_putstr.c	\
		my_strdup.c	\
		my_put_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv libmy.a ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

%.o:	%.c
		@echo "$< => $@"
		@$(CC) $(CFLAGS) -c -o $@ $<
