SRC		=	./src/main.c	\
			./src/lib/*c	\

NAME	=	MarioRun

CC		=	gcc

RM		=	rm -f

OBJ		=	$(SRC:.c=.o)

SDL2_PATH =	-I ./SDL2/include/ -L ./SDL2/lib/

CFLAGS	=	-Wall -std=c99  ./src/include/Icon.o

LDLIBS_WIN	=	-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

LBLIBS_LINUX =	-ldl -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) -o $(NAME) $(SRC) $(SDL2_PATH) $(CFLAGS) $(LDLIBS_WIN)

win 	: 	
			$(CC) -o $(NAME)_win64 $(SRC) $(SDL2_PATH) $(CFLAGS) $(LDLIBS_WIN)
			cls

linux   :  	
			$(CC) -o $(NAME)_linux64 $(SRC) $(CFLAGS) $(LDLIBS_LINUX)
			clear

linux-libs:
			sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev

icon-win	:	
			windres -i ./src/include/Icon.rc -o Icon.o


