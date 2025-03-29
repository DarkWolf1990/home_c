#include "temp_api.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<windows.h>
void print_monthly_stats(const Temperature* temps, int size, int month, int year) {
    int sum = 0;
    int min = INT_MAX;
    int max = INT_MIN;
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (temps[i].year == year && temps[i].month == month) {
            sum += temps[i].temperature;
            if (temps[i].temperature < min) {
                min = temps[i].temperature;
            }
            if (temps[i].temperature > max) {
                max = temps[i].temperature;
            }
            count++;
        }
    }

    if (count > 0) {
        printf("=== Monthly statistics %02d.%d ===\n", month, year);
        printf("Average temperature: %.2f\n", (float)sum / count);
        printf("Minimum temperature: %d\n", min);
        printf("Maximum temperature: %d\n", max);
        printf("==============================\n");
    } else {
        printf("No data for month %02d.%d\n", month, year);
    }
}

// Функция вывода статистики за год
void print_yearly_stats(const Temperature* temps, int size, int year) {
    int sum = 0;
    int min = INT_MAX;
    int max = INT_MIN;
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (temps[i].year == year) {
            sum += temps[i].temperature;
            if (temps[i].temperature < min) {
                min = temps[i].temperature;
            }
            if (temps[i].temperature > max) {
                max = temps[i].temperature;
            }
            count++;
        }
    }

    if (count > 0) {
        printf("=== Annual statistics %d ===\n", year);
        printf("Average annual temperature: %.2f\n", (float)sum / count);
        printf("Minimum temperature: %d\n", min);
        printf("Maximum temperature: %d\n", max);
        printf("=============================\n");
    } else {
        printf("No data for year %d\n", year);
    }
}

// Функция для получения уникальных годов
int get_unique_years(const Temperature* temps, int size, int* years) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        int year = temps[i].year;
        int is_unique = 1;
        for (int j = 0; j < count; j++) {
            if (years[j] == year) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            years[count++] = year;
        }
    }
    return count;
}

// Функция вывода статистики за все годы
void print_all_years_stats(const Temperature* temps, int size) {
    int years[MAX_DAYS];
    int year_count = get_unique_years(temps, size, years);

    for (int i = 0; i < year_count; i++) {
        print_yearly_stats(temps, size, years[i]);
    }
}

// Функция вывода статистики за указанный месяц для всех годов
void print_all_months_stats(const Temperature* temps, int size, int month) {
    int years[MAX_DAYS];
    int year_count = get_unique_years(temps, size, years);

    for (int i = 0; i < year_count; i++) {
        print_monthly_stats(temps, size, month, years[i]);
    }
}

int add_record(Temperature* temps, int* size, Temperature new_record) {
    if (*size >= MAX_DAYS) {
        fprintf(stderr, "The array is full. Unable to add new entry.\n");
        return 0;
    }
    temps[(*size)++] = new_record;
    return 1;
}


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

void sort_temps_by_date(Temperature* temps, int size) {
    qsort(temps, size, sizeof(Temperature), compare_dates);
}


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