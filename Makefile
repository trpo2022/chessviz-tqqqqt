APP = Chessviz
TEST = test

APP_NAME = chessviz
LIB_NAME = libchessviz

CFLAGS = -Wall -Werror
CPPFLAGS = -I src -MMD
TFLAG = -I src -I thirdparty -MMD

BIN = bin
OBJ = obj
SRC = src

TES = test
TP = thirdparty

APP_PATH = $(BIN)/$(APP)
LIB_PATH = $(OBJ)/$(SRC)/$(LIB_NAME).a
TEST_PATH = $(BIN)/$(TEST)

APP_SRC = $(shell find $(SRC)/$(APP_NAME) -name '*.c')
APP_OBJ = $(APP_SRC:$(SRC)/%.c=$(OBJ)/$(SRC)/%.o)

LIB_SRC = $(shell find $(SRC)/$(LIB_NAME) -name '*.c')
LIB_OBJ = $(LIB_SRC:$(SRC)/%.c=$(OBJ)/$(SRC)/%.o)

TEST_SRC = $(shell find $(TES) -name '*.c')
TEST_OBJ = $(TEST_SRC:$(TES)/%.c=$(OBJ)/$(TES)/%.o)

DEPS = $(APP_OBJ:.o=.d) $(LIB_OBJ:.o=.d) $(TEST_OBJ:.o=.d)

.PHONY: $(APP)
$(APP): $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJ) $(LIB_PATH)
	gcc $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(LIB_PATH): $(LIB_OBJ)
	ar rcs $@ $^

$(OBJ)/%.o: %.c
	gcc -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: $(TEST)
$(TEST): $(TEST_PATH)

$(TEST_PATH): $(TEST_OBJ) $(LIB_PATH) 
	gcc $(CFLAGS) $(TFLAG) $^ -o $@

$(OBJ)/%.o: %.c
	gcc -c $(CFLAGS) $(TFLAG) $< -o $@

.PHONY: clean
clean:
	rm -f $(APP_PATH) $(LIB_PATH)
	find $(OBJ) -name '*.o' -exec rm '{}' \;
	find $(OBJ) -name '*.d' -exec rm '{}' \;
	rm -f $(TEST_PATH)
	rm -f output.txt
