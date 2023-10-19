
NAME = cub3D
S_DIR =	srcs

SRC =				$(S_DIR)/parse_infos.c			$(S_DIR)/utilis.c\
					$(S_DIR)/check_infos.c			$(S_DIR)/verifier_texture.c\
					$(S_DIR)/execution.c			$(S_DIR)/check_0_et_jouer.c\
					$(S_DIR)/libere_memoire.c			$(S_DIR)/color_ciel_et_sol_checker.c\
					$(S_DIR)/raycasting.c				$(S_DIR)/initialiser_structs_b.c\
					$(S_DIR)/bosser_avec_textures.c	$(S_DIR)/cub3D.c\
													$(S_DIR)/mlx_fonction.c\


OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror 
all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -Imlx -Ilibft -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	$(MAKE) -C mlx
	$(MAKE) -C libft
	${CC} ${CFLAGS} ${OBJS} -Lmlx -lmlx libft/libft.a -framework OpenGL -framework AppKit -o $@

clean:
	rm -f ${OBJS}
	$(MAKE) clean -C mlx
	$(MAKE) clean -C libft

fclean: clean
	rm -f ${NAME}
	$(MAKE) clean -C mlx
	$(MAKE) fclean -C libft

re: fclean all