#include "temp_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Функция для загрузки данных из CSV-файла
int load_csv(const char* filename, Temperature** records, int* count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    *records = malloc(MAX_RECORDS * sizeof(Temperature));
    if (!*records) {
        perror("Memory allocation failed");
        fclose(file);
        return -1;
    }

    char line[256];
    int line_number = 0;
    *count = 0;

    while (fgets(line, sizeof(line), file) && *count < MAX_RECORDS) {
        Temperature record;
        if (sscanf(line, "%d;%d;%d;%d;%d;%d", 
                   &record.year, &record.month, &record.day, 
                   &record.hour, &record.minute, &record.temperature) != 6) {
            fprintf(stderr, "Error in line %d: Invalid format\n", ++line_number);
            continue;
        }

        // Проверка диапазонов значений
        if (record.temperature < -99 || record.temperature > 99 ||
            record.month < 1 || record.month > 12 ||
            record.day < 1 || record.day > 31 ||
            record.hour < 0 || record.hour > 23 ||
            record.minute < 0 || record.minute > 59) {
            fprintf(stderr, "Error in line %d: Invalid data range\n", ++line_number);
            continue;
        }

        (*records)[(*count)++] = record;
    }

    fclose(file);
    return 0;
}

// Функция для вычисления статистики
void calculate_statistics(const Temperature* temps, int size, Stats monthly_stats[12], Stats* yearly_stats) {
    yearly_stats->min = INT_MAX;
    yearly_stats->max = INT_MIN;
    yearly_stats->sum = 0;

    for (int i = 0; i < size; i++) {
        const Temperature* record = &temps[i];
        int month_index = record->month - 1;

        // Инициализация статистики для месяца
        if (monthly_stats[month_index].count == 0) {
            monthly_stats[month_index].min = record->temperature;
            monthly_stats[month_index].max = record->temperature;
        }

        // Обновление статистики для месяца
        monthly_stats[month_index].count++;
        monthly_stats[month_index].sum += record->temperature;
        if (record->temperature < monthly_stats[month_index].min) {
            monthly_stats[month_index].min = record->temperature;
        }
        if (record->temperature > monthly_stats[month_index].max) {
            monthly_stats[month_index].max = record->temperature;
        }

        // Обновление годовой статистики
        yearly_stats->sum += record->temperature;
        if (record->temperature < yearly_stats->min) {
            yearly_stats->min = record->temperature;
        }
        if (record->temperature > yearly_stats->max) {
            yearly_stats->max = record->temperature;
        }
    }

    yearly_stats->count = size;
}

// Функция вывода статистики за месяц
void print_monthly_stats(const Stats* monthly_stats, int month) {
    if (monthly_stats->count == 0) {
        printf("No data available for month %d\n", month);
        return;
    }

    double avg = (double)monthly_stats->sum / monthly_stats->count;
    printf("Statistics for month %d:\n", month);
    printf("  Average temperature: %.2f\n", avg);
    printf("  Minimum temperature: %d\n", monthly_stats->min);
    printf("  Maximum temperature: %d\n", monthly_stats->max);
}

void print_yearly_stats(const Stats* yearly_stats) {
    if (yearly_stats->count == 0) {
        printf("No data available for the year.\n");
        return;
    }
    // Функция вывода статистики за год
    double avg = (double)yearly_stats->sum / yearly_stats->count;
    printf("Yearly statistics:\n");
    printf("  Average temperature: %.2f\n", avg);
    printf("  Minimum temperature: %d\n", yearly_stats->min);
    printf("  Maximum temperature: %d\n", yearly_stats->max);
}



// Функция добавления записи
int add_record(Temperature* temps, int* size, Temperature new_record) {
    if (*size >= MAX_RECORDS) {
        fprintf(stderr, "The array is full. Unable to add new entry.\n");
        return 0;
    }
    temps[(*size)++] = new_record;
    return 1;
}

// Функция удаления записи
int remove_record(Temperature* temps, int* size, int index) {
    if (index < 0 || index >= *size) {
        fprintf(stderr, "Invalid index for removal.\n");
        return 0;
    }
    for (int i = index; i < (*size) - 1; i++) {
        temps[i] = temps[i + 1];
    }
    (*size)--;
    return 1;
}

// Функция сравнения дат
int compare_dates(const void* a, const void* b) {
    const Temperature* temp_a = (const Temperature*)a;
    const Temperature* temp_b = (const Temperature*)b;

    if (temp_a->year != temp_b->year) {
        return temp_a->year - temp_b->year;
    }
    if (temp_a->month != temp_b->month) {
        return temp_a->month - temp_b->month;
    }
    return temp_a->day - temp_b->day;
}

// Функция сортировки записей по дате
void sort_temps_by_date(Temperature* temps, int size) {
    qsort(temps, size, sizeof(Temperature), compare_dates);
}

// Функция вывода всех записей
void print_temps(const Temperature* temps, int size) {
    printf("=== All records ===\n");
    for (int i = 0; i < size; i++) {
        printf("%d-%02d-%02d %02d:%02d %d\n",
               temps[i].year,
               temps[i].month,
               temps[i].day,
               temps[i].hour,
               temps[i].minute,
               temps[i].temperature);
    }
    printf("==================\n");
}