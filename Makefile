##
## EPITECH PROJECT, 2024
## cvec
## File description:
## Makefile
##

NAME	=	cvec

INC		=	cvec.h

CC		=	gcc

TMPDIR	=	tmp

INST_BIN_DIR	=	/usr/local/lib

INST_INC_DIR	=	/usr/local/include

# Source

TSRC	=	$(shell find tests -type f -name '*.c')

ESRC	=	$(shell find example -type f -name '*.c')

TOBJ	=	$(TSRC:%.c=$(TMPDIR)/%.o)

EOBJ	=	$(ESRC:%.c=$(TMPDIR)/%.o)

# flags

CFLAGS	+=	-Wall -Wextra -Iinclude

TFLAGS	=	-lcriterion -lgcov --coverage -Itests/include

# rules

all: tests_run

install:
	cp include/$(INC) $(INST_INC_DIR)
	ldconfig

uninstall:
	rm -f $(INST_INC_DIR)/$(INC)
	ldconfig

reinstall: uninstall install

clean:
	rm -rf $(TMPDIR)

fclean: clean
	rm -f unit_tests
	rm -f $(NAME)

re: fclean all

unit_tests: CFLAGS += $(TFLAGS)
unit_tests:	$(TOBJ)
	$(CC) -o unit_tests $(TOBJ) $(CFLAGS)

tests_run: unit_tests
	./unit_tests

example:	$(EOBJ)
	$(CC) -o $(NAME) $(EOBJ) $(CFLAGS)

$(TMPDIR)/%.o:	%.c
	@mkdir -p $(@D)
	gcc -o $@ -c $< $(CFLAGS)

.PHONY: all install uninstall reinstall clean fclean re unit_tests tests_run example
