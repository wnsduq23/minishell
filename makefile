# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 15:47:04 by junykim           #+#    #+#              #
#    Updated: 2023/01/06 15:03:13 by junykim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variable
NAME 	= minishell
CC 		= cc
CFLAG	= -Wall -Wextra -Werror -g3 -fsanitize=address
DEL		= rm -rf
ARC		= ar rc
LIBFT	= libft
INC		= .

SRC_FILES = exec_cmd_util \
			execute \
			exec_cmd \
			main1 \
			error \
			util
SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addsuffix .o, $(SRC_FILES))
# Rule

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@make bonus -C $(LIBFT)
	$(CC) $(CFLAG) $(OBJ) $(LIBFT)/libft.a -o $@ -I $(INC)
	@echo "===========minishell started============"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~:!B!:~~^~~~~~^^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~7BGYY57:~~~:Y?:~~~~~~~^^~!!~^~~~~7^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~:?YJ!7777~^^~~:5B~~~^~~~^JPJJYPY^~:?#~^~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^^:?PJ??YP!^~^!BP5J:~~:YB~:^^^BY:^!#7:~~~~^7JJJ!~~!7^~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~:7#7:^^:G5:~~:G5:^~~~:7B?~~~7BJ:^~#?:~~~^^?77?5555?^~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~P57!!YB7:~~:YB^~~~~~^!JYY557^~^!B!^~~~~~~~~^^~~^^~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^^7JJJ?~^~~~^~7^~~~~~~~^^^^^^~~~^~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^^^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!!7??JJJJJ?????77!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!7?JY5555YYYJ??7????JJYYY55YYJJ7!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~7J555J?7~~^^::::::::::::::::^^~!7JY55Y?!~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~7YP5J7^:::::::::::::::::::::::::::::::^~?YP5J7~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~?5PJ!:::::::::::::::::::::::::::::::::::::::^!J55?~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~?Y7~~~~~~~~?PP7^::::::::::::::::::::::::::::::::::::::::::::^7PP?~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~!YP?~~~~~!5P?^:::::::::::::::::::::::::::::::::::::::::::::::::?GJ~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~!!~~~~?GY^::::::::::::::::::::::::::::::::::::::::::::::::::::7G5!~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~7BY:::::::::::::::::::::::::::::::::::::::::::::::::::::::!G5!~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~!Y5J?!~~~~~~~~!GP^::::::::::::::::::::::::::::::::::::::::::::::::::::::::~PP!~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~!7?Y?~~~~~~~~5B~::::::::::::::::::::!557::::::::::^^^:::::::::::::::::::::~B5~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~7BJ:::::::::::::::::::::!Y57:::::::::^5BP^:::::::::::::::::::::YG!~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~JB!::::::::::::::::::::^!???JJ5P5J~!!~77!^:::::::::::::::::::::7B?~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~PP^:::::::::::::::::::~5J^:::!Y55J~77?JY~::::::::::::::::::::::~GY~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~!BJ::::::::::::::::::::!G!    .^~.      JP^::::::::::::::::::::::PP~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~!BJ:::::::::::::::::::::!YJJJJJJJYJ7~:^~YY:::::::::::::::::::::::PP~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~7JYYY5BJ::::::::::::::::::::::::^^^::::~7?JJ?!:::::::::::::::::::::::^G5~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~7P5J7!!7YP?::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::~BJ~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~!G5^::::::^^::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::?B7~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~7B?::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::^PP~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~!P5^:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::7B?~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~7GY^::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::JP!~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~!5P?^::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::~!~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~75PJ^:::::::::::::::::::::::::::::::::::::::::::^::::::::::::::::::5P~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~YP^::::::::::::::::::::::::::::::::::::::::^?5Y~:::::::::::::::::?B7~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~!BY::::::::::::::::::::::::::::::::::::::::JPJ!^::::::::::::::::::~GY~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~?B7:::::::::::::::::::::::::::::::::::::::7B7::::::::::::::::::::::5G~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~5G^:::::::::::::::::::::::::::::::::::::::!B7::::::::::::::::::::::YG!~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~5P^::::::::::::::::::::::::::::::::::::::::?PY7!!!7J!::::::::::::::7B7~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~5P::::::::::::::::::::::::::::::::::::::::::^7JJJJ?7^::::::::::::::?B7~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~5P^::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::5P~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~5P^:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::^G5~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~YB~:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::7BJ!!!~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~7BJ:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::5BPPPP55J!~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~?BJ^7?^::::::::::::::::::::::::::::::::::::::::::::::::::::::::^JBP5YYY5PGGJ~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~7PG57^:::::::::::::::::::::::::::::~^::::::::::::::::::::::::!PGY5BBGBG5J5B?~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~JB!.:::::::::::::::::::::::::::::YP~:::::::::::::::::::^^~75G5JJ55Y5PP5YGG7~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~!5P?7!~~~!7?Y5YYYYYYYYYYYYYYYJJJYBJ:::::::::::^~!7??JYY555YPPPPP55555PPPY!~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~7JY5555YJ?7!!!!!777777777777??7JP5J?777???JY55YYJ??7!!~~~~!!7?JYYYJ?7!~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~7?JJJJJJ??7!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean : 
	$(DEL) $(OBJ)
	make clean -C $(LIBFT)
	@echo "deleted"

fclean : clean
	$(DEL) $(NAME)
	$(DEL) $(LIBFT)/libft.a
	@echo "all deleted"

re : fclean all

.PHONY : all clean fclean re
