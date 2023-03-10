# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 11:45:09 by frmurcia          #+#    #+#              #
#    Updated: 2023/02/22 17:39:39 by frmurcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
GREEN			:= \033[32m
NC				:= \033[m

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

CC = gcc
SRC_CLIENT = client.c aux_c.c errors_c.c
SRC_SERVER = server.c aux_s.c
SRC_BONUS_C = client_bonus.c
SRC_BONUS_S = server_bonus.c

FLAGS = -Wall -Werror -Wextra
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_BONUS_C = $(SRC_BONUS_C:.c=.o)
OBJ_BONUS_S = $(SRC_BONUS_S:.c=.o)

HEADER_CLIENT = client.h
HEADER_SERVER = server.h

RM = rm -f

%.o : %.c $(HEADER_CLIENT) $(HEADER_SERVER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(CLIENT) $(SERVER)
	
$(CLIENT) : $(OBJ_CLIENT) $(HEADER_CLIENT)
	$(CC) $(FLAGS) $(OBJ_CLIENT) -o $(CLIENT)

$(SERVER) : $(OBJ_SERVER) $(HEADER_SERVER)
	$(CC) $(FLAGS) $(OBJ_SERVER) -o $(SERVER)

$(CLIENT_BONUS) : $(OBJ_BONUS_C)
	$(CC) $(FLAGS) $(OBJ_BONUS_C) -o $(CLIENT_BONUS)

$(SERVER_BONUS) : $(OBJ_BONUS_S)
	$(CC) $(FLAGS) $(OBJ_BONUS_S) -o $(SERVER_BONUS)

# all :	$(CLIENT) $(SERVER)

bonus: $(OBJ_BONUS_C) $(OBJ_BONUS_S)
	$(CC) $(FLAGS) $(OBJ_BONUS_C) -o $(CLIENT_BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS_S) -o $(SERVER_BONUS)
	touch $@

clean :
	$(RM) $(OBJ_CLIENT) 
	$(RM) $(OBJ_SERVER)
	$(RM) $(OBJ_BONUS_C)
	$(RM) $(OBJ_BONUS_S)

fclean : clean
	$(RM) $(CLIENT)
	$(RM) $(SERVER)
	$(RM) $(CLIENT_BONUS)
	$(RM) $(SERVER_BONUS)
	$(RM) bonus
	@echo "$(GREEN)$(CLIENT), $(SERVER), $(CLIENT_BONUS) and $(SERVER_BONUS) cleaned!$(NC)"

re : fclean all
norm : 
	@norminette .
.PHONY = all clean fclean re norm bonus
