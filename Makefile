SRCS =			check_array_sorted.c check_integer.c check_unique_elements.c \
				get_stack_size.c initialize_array_of_integers.c \
				initialize_stacks_structure.c main.c push.c quicksort.c \
				rotate_reverse.c rotate.c swap.c utils.c

OBJS_DIR =		objs/

OBJS =			$(addprefix ${OBJS_DIR}, ${SRCS:.c=.o})

DEPS =			$(addprefix ${OBJS_DIR}, ${SRCS:.c=.d})

NAME =			push_swap

LIBFT =			./libft

HEADER =		push_swap.h

CC =			gcc

FLAGS = 		-Wall -Werror -Wextra -O3 -MMD

FLAGS_DEV =		-Wall -Werror -Wextra -g3 -MMD

${OBJS_DIR}%.o: %.c
				${CC} ${FLAGS_DEV} -c $< -o $@

all:			${OBJS_DIR} ${NAME}

${OBJS_DIR}:
				@mkdir -p ${OBJS_DIR}

${LIBFT}:		FORCE
				@${MAKE} -C ./libft all

${NAME}:		${OBJS} ${LIBFT} ${HEADER}
				${CC} ${FLAGS_DEV} -L./libft -lft ${OBJS} -o ${NAME}

FORCE:			;

clean:
				@${MAKE} -C ./libft clean
				@rm -rf ${OBJS_DIR}

fclean:			clean
				@${MAKE} -C ./libft fclean
				@rm -f ${NAME}

re:				fclean all

.PHONY:			all FORCE clean fclean re

-include		${DEPS}
