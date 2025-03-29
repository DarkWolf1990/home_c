CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGET = program
SRCS = main.c temp_api.c
OBJS = $(SRCS:.c=.o)
HDRS = temp_api.h
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Правило для компиляции .c файлов в .o
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Правило для очистки временных файлов
clean:
	rm -f $(OBJS) $(TARGET)

# Правило для запуска программы с тестовым CSV-файлом
run: $(TARGET)
	./$(TARGET) -f temperatures.csv

# Правило для вывода справки
help:
	@echo "Использование: make [команда]"
	@echo "Доступные команды:"
	@echo "  make         - Собрать программу"
	@echo "  make run     - Собрать и запустить программу с тестовым CSV-файлом"
	@echo "  make clean   - Удалить временные файлы и исполняемый файл"
	@echo "  make help    - Вывести эту справку"

.PHONY: clean run help