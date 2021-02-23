# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qli <qli@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/18 10:19:21 by qli           #+#    #+#                  #
#    Updated: 2021/02/18 10:19:21 by qli           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= 	philo_two

SOURCE			= 	main.c \
					srcs/check_status.c \
					srcs/clean_up.c \
					srcs/initialise_philos.c \
					srcs/print.c \
					srcs/process_input.c \
					srcs/start_action.c \
					srcs/time_calculation.c \
					srcs/libft_functions.c

OBJECT			=	$(SOURCE:.c=.o)

COMPILE			= 	gcc

INCLUDE			= 	-I/headers

FLAGS			= 	-Wall -Wextra -Werror -pthread

RESET			= 	\033[0m
GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GREY 			= 	\033[38;5;8m
ORANGE 			= 	\033[38;5;202m
RED 			= 	\033[38;5;160m

all: $(NAME)

%.o: %.c
	@echo "$(GREY)Compiling...				$(GREY)$<"
	@$(COMPILE) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJECT)
	@echo "$(GREEN)----------------------------------------------------"
	@$(COMPILE) $(FLAGS) $(OBJECT) -o $(NAME)
	@echo "Executable				./$(NAME) $(RESET)"

clean:
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(OBJECT)
	@echo "$(GREY)REMOVED O-FILES $(RESET)"

fclean: clean
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(NAME)
	@echo "$(GREY)REMOVED EXECUTABLE FILE $(RESET)"

re: fclean all

.PHONY: all clean fclean re