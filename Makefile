TARGET         := string_manipulation
STRICTFLAGS    := -ansi -Wall -Wextra -Werror -Wpedantic -Wconversion -Wshadow -Wuninitialized -Wformat -Wlogical-op -Wimplicit-fallthrough -Wundef -Wmisleading-indentation -Wnull-dereference -Wduplicate-decl-specifier -Wredundant-decls
DEBUGFLAGS     := -g -D_GNU_SOURCE
C              := gcc
L              := gcc
CINC           := -I. 
LINC           := -I.
CFLAGS         := $(STRICTFLAGS) $(DEBUGFLAGS) $(CINC)
LFLAGS         := $(STRICTFLAGS) $(DEBUGFLAGS) $(LINC)
SRC            := $(wildcard ./*.c)

%.o : %.c
	@$(C) $(CFLAGS) $(CINC) -c $< 

OBJ            := $(SRC:.c=.o)

$(TARGET) : $(OBJ)
	@$(L) $(LFLAGS) $(LINC) $(OBJ) -o $@

clean : $(OBJ) $(TARGET)
	@rm -rf $(OBJ) $(TARGET)

commit :
	@git add .; git commit -m "AUTO COMMIT: $(shell date +'%Y-%m-%d %H:%M:%S')"; git push origin main

run : $(TARGET)
	@./$(TARGET)

all : $(SRC) $(OBJ) $(TARGET)
	@clear; $(MAKE) clean; $(MAKE); $(MAKE) commit; $(MAKE) run;


MAKEFLAGS += --no-print-directory
.PHONY: clean run commit all
