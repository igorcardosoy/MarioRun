SRC		=	./src/main.c	\
			./src/lib/*c	\

NAME	=	MarioRun

CC		=	gcc

RM		=	rm -f

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I ./SDL2/include/ -L ./SDL2/lib/

LDLIBS	=	-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) -std=c99 -o $(NAME) $(SRC) $(CFLAGS) $(LDLIBS)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re