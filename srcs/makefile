
#Compile params
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra

#Files

NAME		= ft_ping
INC_DIR		= ./include/
INC_FILE	+= debug.h
INC_FILE	+= options.h
INC_FILE	+= ping.h
INC_FILE	+= icmphdr.h
INC_FILE	+= iphdr.h
INC_FILE	+= utils.h

INC		= $(addprefix $(INC_DIR), $(INC_FILE))
SRCS_DIR	= ./srcs/
SRCS_FILE	= main.c
SRCS_FILE	+= init_routine.c
SRCS_FILE	+= start_routine.c
SRCS_FILE	+= recv_pckt.c
SRCS_FILE	+= send_pckt.c

## PARSING ##
SRCS_FILE	+= parsing/get_flags.c
SRCS_FILE	+= parsing/set_flags.c
SRCS_FILE	+= parsing/flag_need_param.c
SRCS_FILE	+= parsing/set_simple_flag.c
SRCS_FILE	+= parsing/init_t_options.c
SRCS_FILE	+= parsing/add_mask.c
SRCS_FILE	+= parsing/set_flag_h.c
SRCS_FILE	+= parsing/set_flag_c.c
SRCS_FILE	+= parsing/set_flag_s.c
## IP ##
SRCS_FILE	+= ip/init_iphdr.c
SRCS_FILE	+= ip/create_iphdr.c
## ICMP ##
SRCS_FILE	+= icmp/init_icmphdr.c
SRCS_FILE	+= icmp/create_icmp_pckt.c
## UTILS ## 
SRCS_FILE	+= utils/checksum.c
SRCS_FILE	+= utils/resolve_dns.c
SRCS_FILE	+= utils/create_packet.c

## PING_LIST ##

#For each subdirectory
PARSING_DIR	= $(addprefix $(SRCS_DIR), parsing/)
IP_DIR		= $(addprefix $(SRCS_DIR), ip/)
ICMP_DIR	= $(addprefix $(SRCS_DIR), icmp/)
UTILS_DIR	= $(addprefix $(SRCS_DIR), utils/)

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

$(OBJS_DIR)%.o: $(IP_DIR)%.c $(INC)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIBFT_INC)

$(OBJS_DIR)%.o: $(ICMP_DIR)%.c $(INC)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIBFT_INC)

$(OBJS_DIR)%.o: $(UTILS_DIR)%.c $(INC)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIBFT_INC)

all: $(NAME)
	@echo $(NAME)

$(LIBFTA):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFTA)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTA) -o $(NAME)

debug: CFLAGS += -D DEBUG_TEST
debug: re

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all fclean clean debug
