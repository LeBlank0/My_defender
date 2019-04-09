##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	height.c			\
		scene_set.c			\
		menu_set.c			\
		game_map_set.c		\
		set.c				\
		text_set.c			\
		stat_set.c			\
		road_choice.c		\
		map_set.c			\
		turret_set.c		\
		parallax.c			\
		follow_attack.c		\
		circle_contains.c	\
		dir.c				\
		mob.c				\
		reset.c				\
		game.c				\
		rect.c				\
		event.c				\
		event_click.c		\
		scene_event.c		\
		turret_event.c		\
		draw.c				\
		draw_game.c			\
		destroy.c			\
		destroy_menu.c		\
		my_defender.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

LDFLAGS	=	-L./lib -lmy -lm -l csfml-graphics -l csfml-window \
			-l csfml-audio -l csfml-network -l csfml-system

CFLAGS	=	-g -W -Wall -Wextra -Iinclude

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my/
		make -C lib/my/ fclean
		gcc $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:		 clean
		rm -f lib/libmy.a
		rm -f $(NAME) $(OBJ)

re:		fclean all
