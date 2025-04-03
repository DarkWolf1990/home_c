#include "temp_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

void print_help() {
    printf("Usage: ./program [Keys]\n");
    printf("Keys:\n");
    printf("  -h            Show help.\n");
    printf("  -f <file>     Load data from CSV file.\n");
    printf("  -m <month>    Get statistics for the specified month.\n");
}

int main(int argc, char* argv[]) {
    Temperature* records = NULL;
    int count = 0;
    int month = -1;
    char* filename = NULL;

    // Обработка аргументов командной строки
    int opt;
    while ((opt = getopt(argc, argv, "hf:m:")) != -1) {
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
                    fprintf(stderr, "Invalid month: %d\n", month);
                    return 1;
                }
                break;
            default:
                fprintf(stderr, "Unknown option: %c\n", opt);
                print_help();
                return 1;
        }
    }

    // Загрузка данных из файла
    if (!filename) {
        fprintf(stderr, "Error: No input file specified. Use -f to specify a file.\n");
        return 1;
    }

    if (load_csv(filename, &records, &count) != 0) {
        fprintf(stderr, "Error loading data from file.\n");
        free(records);
        return 1;
    }

    // Инициализация структур для хранения статистики
    Stats monthly_stats[12] = {0};
    Stats yearly_stats = {0};

    for (int i = 0; i < 12; i++) {
        monthly_stats[i].min = INT_MAX;
        monthly_stats[i].max = INT_MIN;
    }
    yearly_stats.min = INT_MAX;
    yearly_stats.max = INT_MIN;

    // Вычисление статистики
    calculate_statistics(records, count, monthly_stats, &yearly_stats);

    // Вывод статистики
    if (month != -1) {
        print_monthly_stats(&monthly_stats[month - 1], month);
    } else {
        for (int i = 0; i < 12; i++) {
            if (monthly_stats[i].count > 0) {
                print_monthly_stats(&monthly_stats[i], i + 1);
            }
        }
        print_yearly_stats(&yearly_stats);
    }

    free(records);
    return 0;
}