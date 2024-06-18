##
## EPITECH PROJECT, 2024
## cvec
## File description:
## Makefile
##

NAME	=	cvec

LIB		=	lib${NAME}.a

INC		=	cvec.h

CC		=	gcc

TMPDIR	=	tmp

INST_BIN_DIR	=	/usr/local/lib

INST_INC_DIR	=	/usr/local/include

# Source

SRC		=	$(shell find src -type f -name '*.c')

TSRC	=	$(shell find tests -type f -name '*.c')

ESRC	=	$(shell find example -type f -name '*.c')

OBJ		=	$(SRC:%.c=$(TMPDIR)/%.o)

TOBJ	=	$(TSRC:%.c=$(TMPDIR)/%.o)

EOBJ	=	$(ESRC:%.c=$(TMPDIR)/%.o)

# flags

CFLAGS	+=	-Wall -Wextra -Iinclude

TFLAGS	=	-lcriterion -lgcov --coverage -Itests/include

# rules

$(LIB):	$(OBJ)
	ar rc $(LIB) $(OBJ)

all: $(LIB)

install:	$(LIB)
	cp $(LIB) $(INST_BIN_DIR)
	cp include/$(INC) $(INST_INC_DIR)
	ldconfig

uninstall:
	rm -f $(INST_BIN_DIR)/$(LIB)
	rm -f $(INST_INC_DIR)/$(INC)
	ldconfig

reinstall: uninstall install

clean:
	rm -rf $(TMPDIR)

fclean: clean
	rm -f $(LIB)
	rm -f unit_tests
	rm -f $(NAME)

re: fclean all

unit_tests: CFLAGS += $(TFLAGS)
unit_tests:	$(LIB) $(TOBJ)
	$(CC) -o unit_tests $(TOBJ) $(LIB) $(CFLAGS)

tests_run: unit_tests
	./unit_tests

example:	$(LIB) $(EOBJ)
	$(CC) -o $(NAME) $(EOBJ) $(LIB) $(CFLAGS)

$(TMPDIR)/%.o:	%.c
	@mkdir -p $(@D)
	gcc -o $@ -c $< $(CFLAGS)

.PHONY: all install uninstall reinstall clean fclean re unit_tests tests_run\
	example
