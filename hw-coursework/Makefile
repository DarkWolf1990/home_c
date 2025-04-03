# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2 -g

# Имя исполняемого файла
TARGET = report

# Исходные файлы
SRCS = report.c temp_functions.c
OBJS = $(SRCS:.c=.o)

# Заголовочные файлы
HDRS = temp_functions.h

# Определение операционной системы
ifeq ($(OS),Windows_NT)
	RM = del /Q
	EXECUTABLE = $(TARGET).exe
else
	RM = rm -f
	EXECUTABLE = $(TARGET)
endif

# Цель: собрать исполняемый файл
$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Правило для компиляции .c файлов в .o
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Правило для очистки временных файлов
clean:
	$(RM) $(OBJS) $(EXECUTABLE)

# Правило для запуска программы с тестовыми CSV-файлами
run: $(EXECUTABLE)
ifeq ($(OS),Windows_NT)
	@if not exist temperature_big.csv ( \
        echo Error: File 'temperature_big.csv' not found. & \
        exit 1 \
    )
	$(EXECUTABLE) -f temperature_big.csv
	@if not exist temperature_small.csv ( \
        echo Error: File 'temperature_small.csv' not found. & \
        exit 1 \
    )
	$(EXECUTABLE) -f temperature_small.csv
else
	@if [ ! -f temperature_big.csv ]; then \
        echo "Error: File 'temperature_big.csv' not found."; \
        exit 1; \
    fi
	./$(EXECUTABLE) -f temperature_big.csv
	@if [ ! -f temperature_small.csv ]; then \
        echo "Error: File 'temperature_small.csv' not found."; \
        exit 1; \
    fi
	./$(EXECUTABLE) -f temperatures_small.csv
endif

# Правило для вывода справки
help:
	@echo "Использование: make [команда]"
	@echo "Доступные команды:"
	@echo "  make         - Собрать программу"
	@echo "  make run     - Собрать и запустить программу с тестовыми CSV-файлами"
	@echo "  make clean   - Удалить временные файлы и исполняемый файл"
	@echo "  make help    - Вывести эту справку"

# Помечаем цели как PHONY
.PHONY: clean run help