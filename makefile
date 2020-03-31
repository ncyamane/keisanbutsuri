SUFFIXE 	:= .c
COMPILER	:= gcc
CFLAGS		:= -std=c11 -g
LDFLAGS		:=
LIBS		:= -lm

SRCDIR		:= src
INCLUDE		:= -I./include
EXEDIR		:= bin

SOURCES 	:= $(wildcard $(SRCDIR)/*$(SUFFIXE))
OBJECT		:= $(patsubst $(SRCDIR)/%.c,$(EXEDIR)/%,$(SOURCES))

.PHONY: all
all: $(OBJECT)

$(EXEDIR)/%:$(SRCDIR)/%.c
	$(COMPILER) $(INCLUDE) $(CFLAGS) $(LIBS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJECT)

