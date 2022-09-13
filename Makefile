CFLAGS = -Wall -Wextra -Werror -I./mlx -g
LFLAGS = -framework AppKit -framework OpenGL -L./mlx -lmlx 
MLX = ./mlx/libmlx.a
GNL = $(wildcard gnl/*c)
GNLOBJS = $(GNL:.c=.o)
SRCS = main.c	map_read.c	errors.c	map_read_utils.c	mlx_put.c	walk.c	xpm_file_control.c
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(MLX) $(NAME)
$(MLX) :
	@make bonus -sC ./ft_printf/libft
	@make -sC ./ft_printf
	@make -sC ./mlx
	@printf '\033[33m Mlx Library compiled. !\n'

$(NAME) : $(OBJS) $(GNLOBJS)
	@gcc -g $(OBJS) $(GNLOBJS) $(LFLAGS) $(CFLAGS) ./ft_printf/libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)
	@printf '\033[32m Files compiled. !'
.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf '\033[33m Compiling...\n'

clean:
	@rm -rf $(OBJS) $(NAME)
	@printf '\033[31m Files deleted. !'

fclean:
	@printf '\033[31m'
	@rm -rf $(OBJS) $(NAME)
	@rm -rf ./gnl/*.o
	@make clean -C ./mlx
	@make fclean -C ./ft_printf/libft
	@make fclean -C ./ft_printf
	@printf '\033[31m Files deleted. !'

norm:
	norminette ./*.c

re : fclean all

test:
	@printf '\033[36m Running Sample File. !'
	./so_long maps/map1.ber
	

.PHONY: clean fclean re norm
