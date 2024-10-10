NAME = fractol
BONUS =fractol_bonus
CCFLGS = -Wall -Wextra -Werror  #-fsanitize=address -g
CC = cc
SRC_FILE =mandatory/main.c \
		 mandatory/mandelbort.c \
		 mandatory/julia.c \
		 mandatory/utils.c \
		 mandatory/utils2.c \
		 mandatory/hooks.c \
		 mandatory/utils_fract.c

SRC_BON = bonus/main.c \
		 bonus/mandelbort.c \
		 bonus/utils2.c \
		 bonus/hooks.c \
		 bonus/utils_fract.c

OBJ_BN =$(SRC_BON :.o:.c)

OBJ = $(SRC_FILE : .o:.c)


%.o: %.c
	 $(CC) $(CCFLGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME):  $(SRC_FILE) $(OBJ)
	 $(CC) $(CCFLGS) $(SRC_FILE) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

bonus :$(BONUS)

$(BONUS): $(SRC_BON) $(OBJ_BN)
	$(CC) $(CCFLGS) $(SRC_BON) $(OBJ_BN) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(BONUS)

clean: $(OBJ) $(OBJ_BN)
	rm -rf $(OBJ) $(OBJ_BN)
fclean: clean
	rm -rf $(NAME) $(BONUS)
re:fclean all