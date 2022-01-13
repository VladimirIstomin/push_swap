SRCS =			checkers/check_array_sorted.c checkers/check_integer.c checkers/check_unique_elements.c \
				initializers/initialize_array_of_integers.c initializers/initialize_stacks_structure.c \
				stack_operations/rotate_reverse.c stack_operations/rotate.c stack_operations/swap.c stack_operations/push.c \
				sort/mini_sort.c sort/full_sort.c sort/quicksort.c sort/calculate_rotations.c \
				main_push_swap.c utils.c

SRCS_CHECKER =	checkers/check_array_sorted.c checkers/check_integer.c checkers/check_unique_elements.c \
				initializers/initialize_array_of_integers.c initializers/initialize_stacks_structure.c \
				stack_operations/rotate_reverse.c stack_operations/rotate.c stack_operations/swap.c stack_operations/push.c \
				main_checker.c sort/quicksort.c utils.c process_instruction.c

OBJS_DIR =		objs/

CHECK_DIR =		checkers/

INIT_DIR =		initializers/

STACK_OPS_DIR =	stack_operations/

SORT_DIR =		sort/

OBJS =			$(addprefix ${OBJS_DIR}, ${SRCS:.c=.o})

OBJS_CHECKER =	$(addprefix ${OBJS_DIR}, ${SRCS_CHECKER:.c=.o})

DEPS =			$(addprefix ${OBJS_DIR}, ${SRCS:.c=.d})

DEPS_CHECKER =	$(addprefix ${OBJS_DIR}, ${SRCS_CHECKER:.c=.d})

NAME =			push_swap

CHECKER =		checker

LIBFT =			./libft

HEADER =		push_swap.h

CC =			gcc

FLAGS = 		-Wall -Werror -Wextra -O3 -MMD

FLAGS_DEV =		-Wall -Werror -Wextra -g3 -MMD

${OBJS_DIR}%.o: %.c
				${CC} ${FLAGS} -c $< -o $@

all:			${NAME}

${OBJS_DIR}:
				@mkdir -p ${OBJS_DIR} ${OBJS_DIR}${CHECK_DIR} ${OBJS_DIR}${INIT_DIR} ${OBJS_DIR}${STACK_OPS_DIR} ${OBJS_DIR}${SORT_DIR}

${LIBFT}:		FORCE
				@${MAKE} -C ./libft all

${NAME}:		${OBJS_DIR} ${OBJS} ${LIBFT} ${HEADER}
				${CC} ${FLAGS} -L./libft -lft ${OBJS} -o ${NAME}

${CHECKER}:		${OBJS_DIR} ${OBJS_CHECKER} ${LIBFT} ${HEADER}
				${CC} ${FLAGS} -L./libft -lft ${OBJS_CHECKER} -o ${CHECKER}

FORCE:			;

clean:
				@${MAKE} -C ./libft clean
				@rm -rf ${OBJS_DIR}

fclean:			clean
				@${MAKE} -C ./libft fclean
				@rm -f ${NAME} ${CHECKER}

re:				fclean all

.PHONY:			all FORCE clean fclean re

-include		${DEPS} ${DEPS_CHECKER}
