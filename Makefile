CC := gcc
AR := ar

BUILD_DIR := build
SRC_DIR := src
INCLUDE_DIR := include

LIB_NAME := libbase.a

CFLAGS := -Wall -Wextra -Wpedantic -g
CPPFLAGS := -I$(INCLUDE_DIR)

SRC := $(SRC_DIR)/base.c
OBJ := $(BUILD_DIR)/base.o
LIB := $(BUILD_DIR)/$(LIB_NAME)

.PHONY: all clean rebuild print

all: $(LIB)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OBJ): $(SRC) $(INCLUDE_DIR)/base/base.h | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIB): $(OBJ)
	$(AR) rcs $@ $^

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean all

print:
	@echo "CC:               $(CC)"
	@echo "AR:               $(AR)"
	@echo "SRC:              $(SRC)"
	@echo "OBJ:              $(OBJ)"
	@echo "LIB:              $(LIB)"
	@echo "INCLUDE_DIR:      $(INCLUDE_DIR)"
