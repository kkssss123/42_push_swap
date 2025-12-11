INC_DIR 	:= ./include
SRC_DIR 	:= ./src/mandatory

CC 			:= cc
CFLAGS 		+= -Wall -Wextra -Werror
CFLAGS		+= -I$(INC_DIR)
CFLAGS		+= $(DBG)	# make DBG="-g -DDEBUG"

LIBFT_DIR 	:= ./libft
LIBFT 		:= $(LIBFT_DIR)/libft.a

NAME 		:= push_swap
SRC			:= $(SRC_DIR)/main.c \
	$(SRC_DIR)/ps_atoi.c \
	$(SRC_DIR)/ps_count_rotate_atob.c \
	$(SRC_DIR)/ps_count_rotate_btoa.c \
	$(SRC_DIR)/ps_get_min_rotate.c \
	$(SRC_DIR)/ps_initialize.c \
	$(SRC_DIR)/ps_lstutils.c \
	$(SRC_DIR)/ps_lstutils2.c \
	$(SRC_DIR)/ps_print_operations.c \
	$(SRC_DIR)/ps_rotate.c \
	$(SRC_DIR)/ps_sort.c \
	$(SRC_DIR)/ps_stack_operations.c \
	$(SRC_DIR)/ps_stack_operations2.c \
	$(SRC_DIR)/ps_validation.c
OBJ			:= $(SRC:.c=.o)

CHECKER		:= checker
BONUS_DIR	:= ./src/bonus
BONUS_SRC	:= $(BONUS_DIR)/main_bonus.c \
	$(BONUS_DIR)/checker_bonus.c
BONUS_OBJ	:= $(BONUS_SRC:.c=.o)
BONUS_OBJ	+= $(filter-out $(SRC_DIR)/main.o, $(OBJ))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -s -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)
	@rm -f $(BONUS_OBJ)

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@rm -f $(CHECKER)

re: fclean all

bonus: $(CHECKER)

$(CHECKER): $(BONUS_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@

.PHONY: all clean fclean re