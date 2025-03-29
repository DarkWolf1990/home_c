#include "temp_api.h"
#include <stdio.h>
#include <limits.h>

// Функция вывода статистики по каждому месяцу
void print_monthly_stats(const Temperature* temps, int size, int month, int year) {
    int sum = 0;
    int min = INT_MAX;
    int max = INT_MIN;
    int count = 0;

    for (int i = 0; i < size; i++) {
        int current_month = (temps[i].month[0] - '0') * 10 + (temps[i].month[1] - '0');
        if (temps[i].year == year && current_month == month) {
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
        printf("=== Статистика за месяц %02d.%d ===\n", month, year);
        printf("Средняя температура: %.2f\n", (float)sum / count);
        printf("Минимальная температура: %d\n", min);
        printf("Максимальная температура: %d\n", max);
        printf("==============================\n");
    } else {
        printf("Нет данных за месяц %02d.%d\n", month, year);
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
        printf("=== Статистика за год %d ===\n", year);
        printf("Среднегодовая температура: %.2f\n", (float)sum / count);
        printf("Минимальная температура: %d\n", min);
        printf("Максимальная температура: %d\n", max);
        printf("=============================\n");
    } else {
        printf("Нет данных за год %d\n", year);
    }
}


