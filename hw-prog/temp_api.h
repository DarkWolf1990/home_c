#ifndef TEMP_API_H  // Защита от повторного включения
#define TEMP_API_H


typedef struct {
    int year;          // Год (4 цифры, например, 2025)
    char month[3];     // Месяц (2 цифры + '\0', например, "01" для января)
    char day[3];       // День (2 цифры + '\0', например, "07")
    char hour[3];      // Часы (2 цифры + '\0', например, "12")
    char minute[3];    // Минуты (2 цифры + '\0', например, "30")
    int temperature;   // Температура в градусах Цельсия (-99 до 99)
} Temperature;

// Прототипы функций вывода статистики
void print_monthly_stats(const Temperature* temps, int size, int month, int year);
void print_yearly_stats(const Temperature* temps, int size, int year);

#endif  // TEMP_API_H