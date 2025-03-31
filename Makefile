# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariaber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 13:39:29 by mariaber          #+#    #+#              #
#    Updated: 2025/03/17 16:13:37 by mariaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# nome del file
NAME = so_long

# percorsi delle librerie
LIBFT_DIR	=	./lib/libft/
GET_DIR		=	./lib/get_next_line/
PRINT_DIR	=	./lib/ft_printf/
MLX_DIR		=	./mlx

# percorsi dei file .a
LIBFT_PATH	=	$(LIBFT_DIR)/libft.a
GET_PATH	=	$(GET_DIR)/get_next_line.a
PRINT_PATH	=	$(PRINT_DIR)/libftprintf.a
MLX_PATH	=	$(MLX_DIR)/libmlx.a

LIB_DIR = $(LIBFT_DIR) $(GET_DIR) $(PRINT_DIR)

# compiler e flag
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I. -I$(LIBFT_PATH) -I$(GNL_PATH) -I$(PRINTF_PATH) -I$(MLX_PATH) -O3

# flag per le librerie
LIB_FLAGS = -L$(LIBFT_DIR) -lft -L$(GET_DIR) -lgnl -L$(PRINT_DIR) -lftprintf
MLX_FLAGS = -L$(MLX_PATH) -lm -lmlx_Linux -lXext -lX11

# inclusione delle librerie
INCLUDES = -I ./includes -I $(MLX_PATH)

SOURCES = so_long.c check.c error.c fill.c free.c init.c maps.c img.c game.c

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(LIB_PATH) $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB_FLAG) $(MLX_FLAG)
	@echo "$(NAME) OK!"

$(LIB_PATH): $(GET_PATH) $(LIBFT_PATH) $(PRINT_PATH) $(MLX_PATH)


$(GET_PATH):
	@$(MAKE) --no-print-directory -C $(GET_DIR)

$(LIBFT_PATH):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(PRINT_PATH):
	@$(MAKE) --no-print-directory -C $(PRINT_DIR)

$(MLX_PATH):
	@$(MAKE) --no-print-directory -C $(MLX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: all

all: $(NAME)

clean:
	@$(RM) $(OBJECTS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@$(MAKE) --no-print-directory -C $(PRINT_DIR) clean
	@$(MAKE) --no-print-directory -C $(GET_DIR) clean
	@$(MAKE) --no-print-directory -C $(MLX_PATH) clean

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_PATH)
	@$(RM) $(GET_PATH)
	@$(RM) $(PRINT_PATH)

re: fclean all

.PHONY: all re clean fclean bonus

