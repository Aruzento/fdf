NAME = fdf

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./minilibx_macos/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

HEADERS_LIST = fdf.h\
	get_next_line.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./srcs/
SOURCES_LIST = fdf_create_matrix.c\
	fdf_draw.c\
	fdf_initialization.c\
	fdf_key.c\
	fdf_main.c\
	fdf_math.c\
	fdf_mlx.c\
	fdf_paint.c\
	fdf_utils.c\
	get_next_line.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objs/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: print $(NAME)
	@echo "\n$(GREEN)Завершено успешно!$(RESET)"
	@echo "\nПроверить норму: make $(YELLOW)norme$(RESET)"
	@echo "\nТы так же можешь скачать карты!\n\tПросто напиши: make $(YELLOW)erandal$(RESET)"
print:
	@clear
	@echo "\n\tПодготовка к $(YELLOW)all$(RESET)..\n"

erandal:
	@rm -rf maps
	@git clone https://github.com/Aruzento/fdf_maps.git maps
	@clear
	@echo "\n\t$(GREEN)Карты и генератор скачаны!$(RESET)"

dot:
	@echo "$(GREEN).$(RESET)\c"

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "]\n-Создание $(GREEN)./$(NAME)$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "-Создание $(GREEN)object directory$(RESET)"
	@echo "-Создание $(GREEN)object files:$(RESET)"
	@echo "-Ожидайте [\c"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN)✓$(RESET)\c"

$(LIBFT):
	@echo "-Создание $(GREEN)$(LIBFT)$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(MINILIBX):
	@echo "-Создание $(GREEN)$(MINILIBX)$(RESET)"
	@$(MAKE) -sC $(MINILIBX_DIRECTORY)

clean:
	@clear
	@echo "\n\tЧистим *.o..."
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@clear
	@echo "\n\t$(GREEN)Все чисто!$(RESET)"

fclean: clean
	@clear
	@echo "\n\tЧистим исполняющие файлы..."
	@rm -f $(MINILIBX)
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@clear
	@echo "\n\t$(GREEN)Все чисто!$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

norme :
	@norminette `find . -type f \( -name *.c -o -name *.h \)` \
	| if ! grep Error -B 1 --color; then echo "\tВсе файлы $(GREEN)по норме$(RESET)!"; fi