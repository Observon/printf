NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = \
	ft_printf.c \
	ft_print_char.c \
	ft_print_string.c \
	ft_print_pointer.c \
	ft_print_number.c \
	ft_print_unsigned.c \
	ft_print_hex.c \
	ft_printf_utils.c

OBJ = $(SRC:.c=.o)

INCLUDES = -I. -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
