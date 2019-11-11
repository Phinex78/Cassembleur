#/*
#** RTP-DVC2, 2019
#** AbstractVM
#** File description:
#**     Makefile
#*/

TARGET   = abstractvm

CC       = gcc

CFLAGS   = -Wall -Werror -Wextra -I.

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f


$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: clean
clean:
	$(rm) $(OBJECTS)

.PHONY: fclean
fclean: clean
	$(rm) $(BINDIR)/$(TARGET)
