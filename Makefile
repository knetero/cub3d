CC = cc
FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c parsing/parsing.c cub_utils/utils.c cub_utils/parsing_utils.c cub3d.c \
       cub_utils/path_parsing_utils.c parsing/rgb_parsing.c parsing/rgb_utils.c parsing/path_parsing.c cub_utils/map_utils.c \
       Libft/ft_split.c Libft/ft_atoi.c Libft/ft_isdigit.c raycasting/raycasting.c raycasting/real_map.c raycasting/free.c\
       graphics/put_pixels.c graphics/textures/rendering_walls.c graphics/mouvement.c graphics/horis_intersection.c graphics/vert_intersection.c\
       graphics/textures/textures.c graphics/textures/txt_utils.c graphics/free_all.c raycasting/utils.c\

OBJS = $(patsubst %.c,build/%.o,$(SRCS))
NAME = cub3D
HEADERS = includes/cub3d.h get_next_line/get_next_line.h Libft/libft.h
LIBFTDIR = ft_libft
LIBFT = ${LIBFTDIR}/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS) ${LIBFT}
	$(CC) $(FLAGS) $(OBJS) -L ${LIBFTDIR} -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

build/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) -Imlx -I $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	${MAKE} clean -C ${LIBFTDIR}

fclean: clean
	rm -f  $(NAME)
	${MAKE} fclean -C ${LIBFTDIR}

re: fclean all
