GNL= srcs/gnl/get_next_line_bonus.c
NAME= fdf.a
SRC= $(GNL) fdf.c ./srcs/fdf/utils.c ./srcs/fdf/read_map.c ./srcs/fdf/draw.c ./srcs/fdf/key_code.c ./srcs/fdf/key_move.c ./srcs/fdf/screenshot.c ./srcs/fdf/utils_draw.c
SRC+= 
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)

$(NAME):	$(OBJ)
	@make -sC ./srcs/libft/
	@cp ./srcs/libft/libft.a ./
	@make -sC ./srcs/minilibx/
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\n\033[36m"****************\\nCompiled...\\n****************\\n"\033[0m\n"

run:
	@clear
	@echo "\n\033[36m"****************\\nStart...\\n****************\\n"\033[0m\n"
	@gcc -Wall -Wextra -Werror ./srcs/minilibx/libmlx.a -framework OpenGL -framework AppKit $(SRC) libft.a -o fdf
	@rm -rf cub3D.dSYM

all: $(NAME)

clean:
	@rm -f $(NAME) $(OBJ) ./src/code
	@make -sC ./srcs/minilibx/ clean
	@make -sC ./srcs/libft/ fclean
	@clear
	@echo "\n\033[36m"****************\\nDeleted files...\\n****************\\n"\033[0m\n"

fclean: clean
		@rm -rf libft.a
		@rm -rf fdf
		@rm -rf fdf.a
	
re: clean all

.PHONY: all clean re run
