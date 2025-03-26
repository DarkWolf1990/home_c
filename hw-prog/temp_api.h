#ifndef TEMP_API_H
#define TEMP_API_H

// Структура для хранения температуры
typedef struct {
    int year;
    char month[3];
    char day[3];
    char hour[3];
    char minute[3];
    int temperature;
} Temperature;

// Прототипы функций вывода статистики
void print_monthly_stats(Temperature* temps, int month, int year);
void print_yearly_stats(Temperature* temps, int year);

#endif  // TEMP_API_H