# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jannabel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 16:50:45 by jannabel          #+#    #+#              #
#    Updated: 2022/01/21 16:51:12 by jannabel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	so_long
NAME_B	=	so_long_bonus
###########################################
SRCS_F	= 	main.c\
			check_ber.c\
			parse_map.c\
			init_map.c\
			check_map.c\
			mlx_utils.c\
			minor_utils.c\
			render.c\
			moves.c
SRCS_D	=	srcs/
SRCS	=	$(addprefix $(SRCS_D),$(SRCS_F))
###########################################
 SRCS_F_B =	main.c\
			check_bonus.c\
			parse_map.c\
			init_map.c\
			check_map.c\
			mlx_utils.c\
			minor_utils.c\
			render.c\
			moves.c
 SRCS_D_B =	srcs_bonus/
 SRCS_B	=	$(addprefix $(SRCS_D_B),$(SRCS_F_B))
###########################################
HEADER	=	srcs/so_long.h   
###########################################
OBJS	=	$(SRCS:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)
###########################################
INCLUDE	=	-I ./include -I./minilibx
###########################################
OPENGL	=	-framework OpenGL -framework AppKit
###########################################
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
###########################################
GNL		=	get_next_line.c \
			get_next_line_utils.c
GNL_D	=	gnl/
GNL_OBJS =	$(addprefix $(GNL_D),$(GNL:.c=.o))
MLX 	=	./minilibx/libmlx.a
LIBFT	=	./libft/libft.a
###########################################
$(NAME): $(OBJS) $(GNL_OBJS) $(HEADER)
	$(MAKE) -C $(dir $(MLX))
	$(MAKE) -C $(dir $(LIBFT))
	cp $(MLX) ./
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT) $(MLX) $(OBJS) $(GNL_OBJS) $(OPENGL) -o $(NAME)
###########################################
all		:	$(NAME)
###########################################
%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
###########################################
clean	:
	$(MAKE) clean -C $(dir $(LIBFT))
	$(MAKE) clean -C $(dir $(MLX))
	rm -rf $(OBJS) $(OBJS_B) $(GNL_OBJS)
###########################################
fclean	:	clean
	$(MAKE) fclean -C $(dir $(LIBFT))
	rm -rf $(NAME) $(NAME_B) libmlx.a
###########################################
bonus	:	$(OBJS_B) $(GNL_OBJS)
	$(MAKE) -C $(dir $(LIBFT))
	$(MAKE) -C $(dir $(MLX))
	cp $(MLX) .
	$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(OBJS_B) $(GNL_OBJS) $(OPENGL) -o $(NAME_B)
###########################################
re 		:	fclean all
###########################################
.PHONY	:	all clean fclean re
###########################################
