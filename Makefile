NAME  = a

FLAGS = -Wall -Werror -Wextra

SRC = get_next_line.c \
		get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

CC = gcc

c.o: ${CC} ${FLAGS} -I get_next_line.h -c $< -o ${<:.c=.o}

all : $(NAME) 

$(NAME) :   $(OBJ)
			${CC} ${FLAGS} -D BUFFER_SIZE=5 ${SRC} 

all:		$(NAME)

clean :
			@rm -f $(OBJ)
			@echo "Get next line OBJ deleted"

fclean : clean
			@rm -f $(NAME)
			@echo "$(NAME) deleted"

testmain : fclean
			${CC} ${FLAGS} -D BUFFER_SIZE=5 -I. $(SRC) main.c && ./a.out

re : fclean all

.PHONY : all fclean clean re testmain

