CC = g++

CFLAGS = -g -I/opt/local/include -Iinclude -O0 -Wall

LDFLAGS = -L/opt/local/lib -lboost_thread-mt -lboost_regex -lboost_program_options -lboost_system

SRC_DIR	  = main messages
BUILD_DIR := $(addprefix build/,$(SRC_DIR))

SRC       := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.cpp))
OBJ       := $(patsubst %.cpp,build/%.o,$(SRC))
INCLUDES  := $(addprefix -I,$(SRC_DIR))

define ld-command
	$(CC) $(LDFLAGS) -o $@ $^
endef

define cc-command
	$(CC) $(CFLAGS) -c $1 -o $@
endef

%.o:
	$(call cc-command, $(patsubst build/%.o,%.cpp,$@))

all: checkdirs bgpd-ng

bgpd-ng: $(OBJ)
	$(ld-command)
	@echo BUILD SUCCEED
	
messages: checkdirs build/messages/BGPMessage.o
	
checkdirs: 
	@mkdir -p $(BUILD_DIR)

clean:
	@rm -rf $(BUILD_DIR)
	@rm -fr bgpd-ng

# This is GNU makefile extension to notify that roughly means: 'clean' does
# not depend on any files in order to call it.
.PHONY: clean checkdirs all

