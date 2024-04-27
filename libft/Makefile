# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 12:16:33 by nusamank          #+#    #+#              #
#    Updated: 2024/04/05 17:09:37 by nusamank         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR = srcs
BINDIR = bin
LIBFTDIR = $(SRCDIR)/libft
FT_PRINTF_DIR = $(SRCDIR)/ft_printf

SRC_LIBFT := $(wildcard $(LIBFTDIR)/*.c)
SRC_FT_PRINTF := $(wildcard $(FT_PRINTF_DIR)/*.c)
OBJ_LIBFT := $(patsubst $(LIBFTDIR)/%.c,$(BINDIR)/%.o,$(SRC_LIBFT))
OBJ_FT_PRINTF := $(patsubst $(FT_PRINTF_DIR)/%.c,$(BINDIR)/%.o,$(SRC_FT_PRINTF))
OBJS = $(OBJ_LIBFT) $(OBJ_FT_PRINTF)

HEAD = includes

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(BINDIR)/%.o: $(LIBFTDIR)/%.c | $(BINDIR)
	$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@
	
$(BINDIR)/%.o: $(FT_PRINTF_DIR)/%.c | $(BINDIR)
	$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@
		
$(BINDIR):
	mkdir -p $(BINDIR)
	
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(BINDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re