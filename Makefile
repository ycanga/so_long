CFLAGS = -Wall -Wextra -Werror -I./mlx -g
LFLAGS = -framework AppKit -framework OpenGL -L./mlx -lmlx
MLX = ./mlx/libmlx.a
GNL = $(wildcard gnl/*c)
GNLOBJS = $(GNL:.c=.o)
SRCS = main.c	map_read.c	errors.c	map_read_utils.c	mlx_put.c
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(MLX) $(NAME)
$(MLX) :
	@make bonus -sC ./ft_printf/libft
	@make -sC ./ft_printf
	@make -sC ./mlx
	@printf '\033[33m Mlx Kütüphanesi Derlendi. !\n'

$(NAME) : $(OBJS) $(GNLOBJS)
	@gcc -g $(OBJS) $(GNLOBJS) $(LFLAGS) ./ft_printf/libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)
	@printf '\033[32m Dosyalar Derlendi. !'
.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf '\033[33m Derleniyor...\n'

clean:
	@rm -rf $(OBJS) $(NAME)
	@printf '\033[31m Dosyalar Silindi. !'

fclean:
	@rm -rf $(OBJS) $(NAME)
	@rm -rf ./gnl/*.o
	@make clean -C ./mlx
	@make fclean -C ./ft_printf/libft
	@make fclean -C ./ft_printf
	@printf '\033[31m Dosyalar Silindi. !'

norm:
	norminette ./*.c

re : fclean all

test:
	@printf '\033[36m Örnek Dosya Çalıştırılıyor. !'
	./so_long maps/map1.ber
	

.PHONY: clean fclean re norm
