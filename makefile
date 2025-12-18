# Makefile
CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -ldl
TARGET = calculator

# Исходные файлы
SRCS = main2.c
OBJS = $(SRCS:.c=.o)

# Цели по умолчанию
all: $(TARGET)

# Сборка основной программы
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Компиляция объектных файлов
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Запуск программы
run: $(TARGET)
	LD_LIBRARY_PATH=. ./$(TARGET)

# Очистка
clean:
	rm -f $(TARGET) $(OBJS)

# Запуск с отладкой
debug: $(TARGET)
	LD_DEBUG=libs LD_LIBRARY_PATH=. ./$(TARGET) 2>&1 | grep -E "loading|init"

.PHONY: all run clean debug