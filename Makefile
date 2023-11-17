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
			$(CC) -o $(NAME)_win64 $(SRC) $(SDL2_PATH) $(CFLAGS) $(LINKER_FLAGS)
			cls  

linux   :  	
			$(CC) -o $(NAME)_linux $(SRC) $(CFLAGS) $(LDLIBS_LINUX)
			clear

linux-libs:
			sudo apt-get install libsdl2-dev
  			sudo apt-get install libsdl2-image-dev
 			sudo apt-get install libsdl2-mixer-dev
  			sudo apt-get install libsdl2-ttf-dev

icon	:	
			windres -i ./src/include/Icon.rc -o Icon.o

