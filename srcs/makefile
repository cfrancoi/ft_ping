
#Compile params
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=address

#Files

NAME		= ft_ping
INC_DIR		= ./include/
INC_FILE	+= debug.h
INC_FILE	+= options.h
INC		= $(addprefix $(INC_DIR), $(INC_FILE))
SRCS_DIR	= ./srcs/
SRCS_FILE	= main.c
SRCS_FILE	+= parsing/get_flags.c
SRCS_FILE	+= parsing/set_flags.c
SRCS_FILE	+= parsing/flag_need_param.c
SRCS_FILE	+= parsing/set_simple_flag.c
SRCS_FILE	+= parsing/init_t_options.c
SRCS_FILE	+= parsing/add_mask.c
SRCS_FILE	+= parsing/set_flag_h.c
SRCS_FILE	+= parsing/set_flag_c.c
SRCS_FILE	+= parsing/set_flag_s.c
#For each subdirectory
PARSING_DIR	= $(addprefix $(SRCS_DIR), parsing/)

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILE))
OBJS_DIR	= ./objs/
OBJS		= $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o))) 

#libft
LIBFT_DIR	= ./libft/
LIBFT_INC	= $(LIBFT_DIR)
LIBFTA		= $(LIBFT_DIR)libft.a

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INC)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIBFT_INC)

$(OBJS_DIR)%.o: $(PARSING_DIR)%.c $(INC)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIBFT_INC)


all: $(NAME)
	@echo $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

debug: CFLAGS += -D DEBUG_TEST
debug: re

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all fclean clean debug
