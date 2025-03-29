/*
* На основе ДЗ предыдущего урока реализовать:
Функции вывода статистики по каждому месяцу:  среднемесячная температура, минимальная температура в текущем месяце,
* максимальная температура в текущем месяце, вывода статистику за год:
* • среднегодовая температура
* • минимальная температура
* • максимальная температура
Функции добавления, удаления записей, сортировки и создания массива структур, печати массива
Приложение должно обрабатывать аргументы командной строки: минимальный набор поддерживаемых ключей:
*  • -h Описание функционала приложения. Список ключей, которые обрабатывает данное приложение и их назначение.
*  • -f входной файл csv для обработки.
*  • -m <номер месяца> если задан данный ключ, то выводится только статистика за указанный месяц.

 *
 *
 * */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp_api.h"


void print_help() {
    printf("Using: ./program [Keys]\n");
    printf("Keys:\n");
    printf("  -h            Check out.\n");
    printf("  -f <file>     Load data from CSV file.\n");
    printf("  -m <month>    Get statistics for the month.\n");
    printf("  -y <year>     Get statistics for the given year.\n");
}


int load_csv(const char* filename, Temperature* temps, int max_days) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("failure to open file");
        return 0;
    }

    int count = 0;
    char line[100];
    while (fgets(line, sizeof(line), file) && count < max_days) {
        sscanf(line, "%d-%d-%d %d:%d %d",
               &temps[count].year,
               &temps[count].month,
               &temps[count].day,
               &temps[count].hour,
               &temps[count].minute,
               &temps[count].temperature);
        count++;
    }

    fclose(file);
    return count;
}

int main(int argc, char* argv[]) {
    Temperature temps[MAX_DAYS];
    int size = 0;
    int month = -1;
    int year = -1;
    char* filename = NULL;

    // Обработка аргументов командной строки
    int opt;
    while ((opt = getopt(argc, argv, "hf:m:y:")) != -1) {
        switch (opt) {
            case 'h':
                print_help();
                return 0;
            case 'f':
                filename = optarg;
                break;
            case 'm':
                month = atoi(optarg);
                if (month < 1 || month > 12) {
                    fprintf(stderr, "Wrong number of month: %d\n", month);
                    return 1;
                }
                break;
            case 'y':
                year = atoi(optarg);
                if (year < 0) {
                    fprintf(stderr, "Bad year: %d\n", year);
                    return 1;
                }
                break;
            default:
                fprintf(stderr, "Unknown key: %c\n", opt);
                print_help();
                return 1;
        }
    }

    // Загрузка данных из файла
    if (filename) {
        size = load_csv(filename, temps, MAX_DAYS);
        if (size == 0) {
            fprintf(stderr, "Error loading data from file.\n");
            return 1;
        }
    }

    // Вывод статистики
    if (month != -1) {
        if (year != -1) {
            print_monthly_stats(temps, size, month, year);
        } else {
            print_all_months_stats(temps, size, month);
        }
    } else {
        if (year != -1) {
            print_yearly_stats(temps, size, year);
        } else {
            print_all_years_stats(temps, size);
        }
    }

    return 0;
}