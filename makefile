CSUFFIXE 	:= .c
CPPSUFFIXE 	:= .cpp

CC			:= gcc
CFLAGS		:= -std=c11 -g

CPP 		:= g++
CPPFLAGS	:= -std=c++17 -g

LDFLAGS		:=
LIBS		:= -lm

CSRCDIR		:= csrc
CPPSRCDIR	:= cppsrc

INCLUDE		:= -I./include

CEXEDIR		:= cbin
CPPEXEDIR	:= cppbin

CSOURCES 	:= $(wildcard $(CSRCDIR)/*$(SUFFIXE))
CPPSOURCES 	:= $(wildcard $(CPPSRCDIR)/*$(CPPSUFFIXE))

COBJECT		:= $(patsubst $(CSRCDIR)/%.c,$(CEXEDIR)/%,$(CSOURCES))
CPPOBJECT	:= $(patsubst $(CPPSRCDIR)/%.cpp,$(CPPEXEDIR)/%,$(CPPSOURCES))

.PHONY: call
call: $(COBJECT)

.PHONY: cppall
cppall: $(CPPOBJECT)

$(CEXEDIR)/%:$(CSRCDIR)/%.c
	$(CC) $(INCLUDE) $(CFLAGS) $(LIBS) -o $@ $<

$(CPPEXEDIR)/%:$(CPPSRCDIR)/%.cpp
	$(CPP) $(INCLUDE) $(CPPFLAGS) $(LIBS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJECT)

