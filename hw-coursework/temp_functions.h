#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#include <stdio.h>

// Максимальное количество записей (для фиксированных массивов)
#define MAX_RECORDS 100000

// Структура для хранения данных о температуре
typedef struct {
    int year;          // Год (4 цифры, например, 2025)
    int month;         // Месяц (число от 1 до 12)
    int day;           // День (число от 1 до 31)
    int hour;          // Часы (число от 0 до 23)
    int minute;        // Минуты (число от 0 до 59)
    int temperature;   // Температура в градусах Цельсия (-99 до 99)
} Temperature;

// Структура для хранения статистики
typedef struct {
    int count;         // Количество записей
    int sum;           // Сумма температур
    int min;           // Минимальная температура
    int max;           // Максимальная температура
} Stats;

// Функции для работы с данными
int load_csv(const char* filename, Temperature** records, int* count);
void calculate_statistics(const Temperature* temps, int size, Stats monthly_stats[12], Stats* yearly_stats);

// Функции для вывода статистики
void print_monthly_stats(const Stats* monthly_stats, int month);
void print_yearly_stats(const Stats* yearly_stats);

// Вспомогательные функции
int add_record(Temperature* temps, int* size, Temperature new_record);
int remove_record(Temperature* temps, int* size, int index);
void sort_temps_by_date(Temperature* temps, int size);
void print_temps(const Temperature* temps, int size);

#endif // TEMP_FUNCTIONS_H