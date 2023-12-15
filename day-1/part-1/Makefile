NAME = trebuchet

SRC = src/trebuchet.c 

OBJ = ${SRC:.c=.o}

CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -g
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = libft
LIBFT = -L ${LIBFT_PATH} -lft

GREEN		= \033[38;5;47m
YELLOW		= \033[38;5;226m
RED			= \033[38;5;196m
END 		= \033[0m

.c.o:
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}
	@echo "[$(GREEN)compiling$(END)]: $<"

${NAME}: ${OBJ}
	@${MAKE} ${LIBFT_PATH}
	@${CC} ${OBJ} ${LIBFT} -o ${NAME}
	@echo "$(GREEN)$(NAME) created$(END)"

all: ${NAME}

clean:
	@${MAKE} ${LIBFT_PATH} clean
	@${RM} ${OBJ}
	@echo "$(RED)cleaning objects$(END)"

fclean: clean
	@${MAKE} ${LIBFT_PATH} fclean
	@${RM} ${NAME}
	@echo "$(RED)$(NAME) deleted$(END)"

re: fclean all