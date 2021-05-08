# https://en.wikipedia.org/wiki/Makefile

CXX         	:= gcc
SRCDIR 			:= .
OBJDIR			:= ./out
EXECUTABLE    	:= gram
type		 	:= 
FLAGS.leak 		:= -fsanitize=address
CXXFLAGS      	:= -std=c11 ${FLAGS.${type}} 
SRCFILES	 	:= $(shell find $(SRCDIR) -name "*.c")
SRCNAMES		:= $(notdir $(SRCFILES))
OBJFILES 	    := $(SRCNAMES:%.c=$(OBJDIR)/%.o)
LDFLAGS       	:= 
space :=
VPATH := $(subst $(space),:,$(shell find . -type d))

# MAIN

.PHONY: all
all: out/$(EXECUTABLE)

out/$(EXECUTABLE): $(OBJFILES)
	@$(CXX) $(OBJFILES) -o $@ $(LDFLAGS) $(CXXFLAGS) && echo "[OK] $@"

$(OBJDIR)/%.o: %.c
	@$(CXX) -c -g $< -o $@ $(LDFLAGS) $(CXXFLAGS) && echo "[OK]  $@"


# CLEAN
.PHONY: clean
clean:
	@rm -f out/* && echo "[CL]  out/"