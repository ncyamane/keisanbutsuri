SUFFIXE = .c
COMPILER	:= gcc
CFLAGS		:= -std=c11 -g
LDFLAGS		:=

SRCDIR		:= ./src
INCLUDE		:= -I./include
EXEDIR		:= ./bin

SOURCES 	= $(wildcard $(SRCDIR)/*$(SUFFIXE))
OBJECTS 	= $(notdir $(SOURCES:$(SUFFIXE)=.o))
TARGETS 	= $(notdir $(basename $(SOURCES)))

define MAKEALL
$(1): $(1).o
	$(COMPILER) $(INCLUDE) $(CFLAGS) -o $(EXEDIR)/$(1) $(1).o
	@$(RM) $(1).o
$(1).o:
	$(COMPILER) $(INCLUDE) $(CFLAGS) -c $(SRCDIR)/$(1)$(SUFFIX)
endef

.PHONY: all
all: $(TARGETS)
	$(foreach VAR,$(TARGETS),$(eval $(call MAKEALL,$(VAR))))

#make clean
.PHONY: clean
clean:
	$(RM) $(EXEDIR)/*