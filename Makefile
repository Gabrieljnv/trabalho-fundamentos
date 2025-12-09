CC := gcc
CFLAGS := -Wall -Wextra -g -I./src -I./tests/munit

SRC_DIR := src
TEST_DIR := tests

SRCS := $(SRC_DIR)/arquivo_utils.c \
        $(SRC_DIR)/clientes.c \
        $(SRC_DIR)/main.c \
        $(SRC_DIR)/quarto.c \
        $(SRC_DIR)/utils.c \
        $(SRC_DIR)/estadia.c \

OBJS := $(SRCS:.c=.o)

TARGET := trabalho

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: tests
test: $(TARGET)
	$(CC) $(CFLAGS) $(TEST_DIR)/test_cliente.c -o test_cliente $(OBJS)
	./test_cliente

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) $(TEST_DIR)/test_cliente



