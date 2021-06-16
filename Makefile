GNL= srcs/gnl/get_next_line_bonus.c

NAME= fdf.a

SRC= $(GNL) ./srcs/fdf/utils.c ./srcs/fdf/read_map.c ./srcs/fdf/draw.c ./srcs/fdf/utils_draw.c ./srcs/fdf/utils_fdf.c

SRCB = ./srcs/fdf/fdf_bonus/key_kode.c ./srcs/fdf/fdf_bonus/key_move.c ./srcs/fdf/fdf_bonus/screenshot.c

OBJS=$(SRC:.c=.o)

OBJB=${SRCB:.c=.o}

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	@make -sC ./srcs/libft/
	@cp ./srcs/libft/libft.a ./
	@make -sC ./srcs/minilibx/
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\n\033[36m"****************\\nCompiled...\\n****************\\n"\033[0m\n"

run:
	@clear
	@echo "\n\033[36m"****************\\nStart...\\n****************\\n"\033[0m\n"
	@gcc -Wall -Wextra -Werror  fdf.c  ./srcs/minilibx/libmlx.a -framework OpenGL -framework AppKit $(SRC) libft.a -o fdf
	@rm -rf cub3D.dSYM


bonus:
		bonus:		${OBJS} ${OBJB}
		ar rc  ${NAME} ${OBJB}
		ranlib ${NAME}
		@gcc -Wall -Wextra -Werror  fdf_bonus.c  ./srcs/minilibx/libmlx.a -framework OpenGL -framework AppKit $(SRC) libft.a -o fdfb

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
		@rm -rf fdfb
	
re: clean all

.PHONY: all clean re run
