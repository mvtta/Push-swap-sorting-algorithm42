# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/23 18:08:33 by mvaldeta          #+#    #+#              #
#    Updated: 2021/05/23 20:13:18 by mvaldeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#MYRULES
COMMON		= common
CHECKER		= checker
PUSH		= push_swap
PSLIB_A		= pslib.a

#compilation
COMP		= gcc -Wall -Werror -Wextra -I includes -I pslib/inlcudes -I pslib/pslib -c -o

#object_directory
OBJ_DIR		= obj/
COM_SRC_DIR = srcs/common/
CHE_SRC_DIR	= srcs/checker/
PU_SRC_DIR 	= srcs/push_swap/

#COMMON SRCS
COM_SRC		= $(wildcard ./srcs/common/*.c)

#CHECKER SRCS
CHE_SRC		= $(wildcard ./srcs/checker/*.c)

#PUSH_SWAP SRCS
PU_SRC		= $(wildcard ./srcs/push_swap/*.c)

#OBJS
COM_OBJ		= $(COM_SRC:%.c=%.o)
CHE_OBJ		= $(CHE_SRC:%.c=%.o)
PU_OBJ		= $(PU_SRC:%.c=%.o)
OBJ			=$(COM_OBJ) $(CHE_OBJ) $(PU_OBJ)

#SRCS_PATH
COM_SRC_PATH	= $(COM_SRC:%=$(COM_SRC_DIR)%)
CHE_SRC_PATH	= $(CHE_SRC:%=$(CHE_SRC_DIR)%)
PU_SRC_PATH		= $(PU_SRC:%=$(PU_SRC_DIR)%)
OBJ_PATH		= $(COM_OBJ_PATH) $(CHE_OBJ_PATH) $(PU_OBJ_PATH)

all:			color do_lib $(OBJ_DIR) $(NAME)
				@echo "\\n\033[32;1m PUSH_SWAP AND CHECKER COMPLETE \033[0m \\n"

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@echo Create: Object directory

$(NAME):		$(OBJ_PATH)
				@gcc $(COM_OBJ_PATH) $(PU_OBJ_PATH) *.a -o push_swap \
					-I includes -I libft/includes
				@gcc $(COM_OBJ_PATH) $(CHE_OBJ_PATH) *.a -o checker \
					-I includes -I libft/includes

$(COM_OBJ_PATH):$(COM_SRC_PATH)
						@$(MAKE) $(COM_OBJ)
						
$(P_OBJ_PATH):	$(PU_SRC_PATH)
					@$(MAKE) $(PU_OBJ)
					
$(COM_OBJ_PATH):$(COM_SRC_PATH)
				@$(MAKE) $(COM_OBJ)
				
$(COM_OBJ):		$(PSLIB_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(COM_SRC_DIR)$(@:%.o=%.c)

$(CHE_OBJ):		$(PSLIB_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(COM_SRC_DIR)$(@:%.o=%.c)

$(P_OBJ):		$(PSLIB_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(PU_SRC_DIR)$(@:%.o=%.c)

do_lib:
				@make -C $(PSLIB)
				@cp $(PSLIB)/$(PSLIB_A) .

colour:
				@echo "\x1b[36m""\x1b[1A\x1b[M"

clean:			color
				@/bin/rm -rf $(OBJ_DIR) $(PSLIB_A)
				@make -C $(PSLIB) clean
				@echo "\\n\033[32;1m Cleaned library object files \033[0m

fclean:			clean
				@/bin/rm -f $(PUSH_SWAP) $(CHECKER) $(PSLIB_A)
				@make -C $(PSLIB) fclean
				@echo "\\n\033[32;1m Cleaned $(NAME) \033[0m \\n"

re: 			fclean all

.PHONY:			all clean flcean re color
