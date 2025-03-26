#include "temp_api.h"
#include <stdio.h>

// Функция вывода статистики по каждому месяцу
void print_monthly_stats(Temperature* temps, int month, int year) {
    int sum = 0;
    int min = 100;
    int max = -100;
    int count = 0;

    for (int i = 0; i < 365; i++) {
        if (temps[i].year == year && temps[i].month[0] == month + '0' && temps[i].month[1] == ' ') {
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
        printf("Среднемесячная температура: %.2f\n", (float)sum / count);
        printf("Минимальная температура в текущем месяце: %d\n", min);
        printf("Максимальная температура в текущем месяце: %d\n", max);
    } else {
        printf("Нет данных за текущий месяц\n");
    }
}

// Функция вывода статистики за год
void print_yearly_stats(Temperature* temps, int year) {
    int sum = 0;
    int min = 100;
    int max = -100;
    int count = 0;

    for (int i = 0; i < 365; i++) {
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
        printf("Среднегодовая температура: %.2f\n", (float)sum / count);
        printf("Минимальная температура: %d\n", min);
        printf("Максимальная температура: %d\n", max);
    } else {
        printf("Нет данных за текущий год\n");
    }
}