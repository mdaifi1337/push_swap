NAME= push_swap
NAME2= checker
FLAGS= -Wall -Werror -Wextra
SRCS= calc_actions_b.c errors.c find_best_elmnt.c longest_inc_seq.c main.c \
	normal_rotate.c push.c push_swap.c rotate.c smart_rotate.c \
	stack_of_three.c swap.c tools.c
SRCS2= calc_actions_b.c errors.c find_best_elmnt.c longest_inc_seq.c \
	normal_rotate.c push.c push_swap.c rotate.c smart_rotate.c \
	stack_of_three.c swap.c tools.c checker.c checker_tools.c
OBJS= $(SRCS:.c=.o)
OBJS2= $(SRCS2:.c=.o)
LIBFT= libft/libft.a
all : libft $(NAME) $(NAME2)

libft:
	@make -C ./libft -j
$(NAME): $(LIBFT) $(OBJS)
	@gcc $(LIBFT) $(OBJS) $(FLAGS) -o $(NAME)
	@echo
	@echo "~~~~~~~~ \033[1;36mSuccessfully generated push_swap\033[0m ~~~~~~~~"
	@echo
$(NAME2): $(LIBFT) $(OBJS2)
	@gcc $(LIBFT) $(OBJS2) -o $(NAME2)
	@echo
	@echo "~~~~~~~~ \033[1;36mSuccessfully generated push_swap\033[0m ~~~~~~~~"
	@echo

%.o: %.c
		@echo Compiling : $< "\x1B[1;32m[OK]\x1B[0m"
		@gcc  -g -c $< -o $@
clean:
		@make clean -C ./libft
		@rm -f *.o
fclean: clean
		@make fclean -C ./libft
		@rm -f miniRT.bmp
		@rm -f $(NAME) $(NAME2)
		@echo "~~~~~~~~ \033[1;36mSuccessfully deleted push_swap\033[0m ~~~~~~~~"
re: fclean all

.PHONY: libft