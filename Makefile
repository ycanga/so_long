SRCS			=	deneme.c
										

OBJS			= $(SRCS:.c=.o)

CC				= gcc #-fsanitize=address -g
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= so_long
LIB				= ./mlx/libmlx.a

all:			$(LIB) $(NAME)

$(LIB) : 
	make -C ./mlx

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -framework OpenGL -framework AppKit -o $(NAME) $(LIB)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

%.o: %.c
	 $(CC) $(CFLAGS) -I./mlx -c $< -o $@

norm:			
				norminette *.[ch]

.PHONY:			all clean fclean re bonus