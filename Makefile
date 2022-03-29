APP = Chessviz

APP_NAME = chessviz
LIB_NAME = libchessviz

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -MMD

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APP)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a

APP_SRC = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.c')
APP_OBJ = $(APP_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SRC = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.c')
LIB_OBJ = $(LIB_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJ:.o=.d) $(LIB_OBJ:.o=.d)

.PHONY: $(APP)
$(APP): $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJ) $(LIB_PATH)
	gcc $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(LIB_PATH): $(LIB_OBJ)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	gcc -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(APP_PATH) $(LIB_PATH)
	find $(OBJ_DIR) -name '*.o' -exec rm '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec rm '{}' \;
