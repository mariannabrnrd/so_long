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
LIBFT_DIR	=	lib/libft/
GET_DIR		=	lib/get_next_line/
PRINT_DIR	=	lib/ft_printf/
MLX_DIR		=	mlx

# percorsi dei file .a
LIBFT_PATH	=	$(LIBFT_DIR)/libft.a
GET_PATH	=	$(GET_DIR)/libgnl.a
PRINT_PATH	=	$(PRINT_DIR)/libftprintf.a
MLX_PATH	=	$(MLX_DIR)/libmlx.a

# compiler e flag
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I. -I$(LIBFT_DIR) -I$(GET_DIR) -I$(PRINT_DIR) -I$(MLX_DIR) -O3

# inclusione delle librerie
INCLUDES = -I ./includes -I $(MLX_DIR)

SOURCES = so_long.c check.c error.c fill.c free.c init.c maps.c img.c game.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_PATH) $(GET_PATH) $(PRINT_PATH) $(MLX_PATH) $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) -L$(LIBFT_DIR) -lft -L$(GET_DIR) -lgnl -L$(PRINT_DIR) -lftprintf -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
	@echo "$(NAME) OK!"

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

clean:
	@$(RM) $(OBJECTS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@$(MAKE) --no-print-directory -C $(PRINT_DIR) clean
	@$(MAKE) --no-print-directory -C $(GET_DIR) clean
	@$(MAKE) --no-print-directory -C $(MLX_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_PATH)
	@$(RM) $(GET_PATH)
	@$(RM) $(PRINT_PATH)

re: fclean all

.PHONY: all re clean fclean bonus