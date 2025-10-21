# **************************************************************************** #
#                                  INCLUDES                                    #
# **************************************************************************** #

NAME         = Bureaucrat
CC           = c++
CFLAGS       = -Wall -Wextra -Werror -std=c++98 -g
OPTIONS      = -I ./includes
RM           = rm -rf


# **************************************************************************** #
#                                  SOURCES                                     #
# **************************************************************************** #

SRC_DIR      = src
SRC_FILES    = main.cpp \
				Bureaucrat.cpp \
				AForm.cpp \
				PresidentialPardonForm.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \



SRC          = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ_DIR      = obj
OBJS         = $(SRC_FILES:%.cpp=$(OBJ_DIR)/%.o)

# **************************************************************************** #
#                                 COULEURS                                     #
# **************************************************************************** #

GREEN        = \033[32m
RED          = \033[31m
YELLOW       = \033[33m
BLUE         = \033[34m
RESET        = \033[0m

# **************************************************************************** #
#                                 MESSAGES                                     #
# **************************************************************************** #

SUCCESS_MSGS = "Compilation réussie, ma reine !" \
               "Le triomphe vous appartient à nouveau, ma princesse !" \
               "C'était trop facile pour vous, ma reine." \
               "Victoire magistrale, mon impératrice !"

FCLEAN_MSGS  = "Ils ont bien été annihilés, vous dominerez le monde, ma reine." \
               "L'exécutable a disparu, il ne reste que des cendres..." \
               "Purification totale effectuée, votre domination se poursuit." \
               "Adieu les fichiers, ils n’étaient pas dignes de vous, ma princesse."

random_success_msg = $(shell printf "%s\n" $(SUCCESS_MSGS) | shuf -n1)
random_fclean_msg  = $(shell printf "%s\n" $(FCLEAN_MSGS)  | shuf -n1)

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

# ---------- EXÉCUTABLE ---------- #
$(NAME): $(OBJS) 
	@echo "$(BLUE)Linking objects...$(RESET)"
	@$(CC) $(CFLAGS) $(OPTIONS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(random_success_msg)$(RESET)"

# ---------- COMPILATION DES .cpp EN .o ---------- #
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OPTIONS) -c $< -o $@

# ---------- CLEAN ---------- #
clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)Objets supprimés.$(RESET)"

# ---------- FCLEAN ---------- #
fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)Exécutable supprimé.$(RESET)"
	@echo "$(GREEN)✓ $(random_fclean_msg)$(RESET)"

# ---------- RE ---------- #
re: fclean all

.PHONY: all clean fclean re
