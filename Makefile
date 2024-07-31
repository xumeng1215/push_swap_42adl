NAME = pushswap
CHECKER = checker

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = src
OBJDIR = obj
LIBFTDIR = libft
FT_PRINTF_DIR = ft_printf
CHECKERDIR = bonus

# Source files for pushswap
SRC = $(SRCDIR)/args_check.c \
      $(SRCDIR)/count_and_set.c \
      $(SRCDIR)/count_and_set_2.c \
      $(SRCDIR)/do_op.c \
      $(SRCDIR)/do_op_2.c \
      $(SRCDIR)/find_place.c \
      $(SRCDIR)/op_push.c \
      $(SRCDIR)/op_rev_rotate.c \
      $(SRCDIR)/op_rotate.c \
      $(SRCDIR)/op_swap.c \
      $(SRCDIR)/pushswap.c \
      $(SRCDIR)/sort.c \
      $(SRCDIR)/stack_util.c \
      $(SRCDIR)/stack_util_2.c

# Object files for pushswap
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Source files for checker
CHECKER_SRC = $(CHECKERDIR)/checker.c \
              $(CHECKERDIR)/checker_util.c \
              $(CHECKERDIR)/get_next_line.c \
              $(CHECKERDIR)/get_next_line_utils.c \
              $(SRCDIR)/args_check.c \
              $(SRCDIR)/count_and_set.c \
              $(SRCDIR)/count_and_set_2.c \
              $(SRCDIR)/do_op.c \
              $(SRCDIR)/do_op_2.c \
              $(SRCDIR)/find_place.c \
              $(SRCDIR)/op_push.c \
              $(SRCDIR)/op_rev_rotate.c \
              $(SRCDIR)/op_rotate.c \
              $(SRCDIR)/op_swap.c \
              $(SRCDIR)/sort.c \
              $(SRCDIR)/stack_util.c \
              $(SRCDIR)/stack_util_2.c

# Object files for checker
CHECKER_OBJ = $(CHECKER_SRC:$(CHECKERDIR)/%.c=$(OBJDIR)/%.o)

# Libraries
LIBFT = $(LIBFTDIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a

# Include directories
INCLUDES = -I $(SRCDIR) -I $(LIBFTDIR) -I $(FT_PRINTF_DIR) -I $(CHECKERDIR)

# Rules
all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(CHECKER): $(CHECKER_OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) $(LIBFT) $(FT_PRINTF) -o $(CHECKER)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o: $(CHECKERDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re