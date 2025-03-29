#ifndef TEMP_API_H
#define TEMP_API_H

#define MAX_DAYS 365

typedef struct {
    int year;          // Год (4 цифры, например, 2025)
    int month;         // Месяц (число от 1 до 12)
    int day;           // День (число от 1 до 31)
    int hour;          // Часы (число от 0 до 23)
    int minute;        // Минуты (число от 0 до 59)
    int temperature;   // Температура в градусах Цельсия (-99 до 99)
} Temperature;

void print_monthly_stats(const Temperature* temps, int size, int month, int year);
void print_yearly_stats(const Temperature* temps, int size, int year);
void print_all_months_stats(const Temperature* temps, int size, int month);
void print_all_years_stats(const Temperature* temps, int size);


int add_record(Temperature* temps, int* size, Temperature new_record);
int remove_record(Temperature* temps, int* size, int index);
void sort_temps_by_date(Temperature* temps, int size);
void print_temps(const Temperature* temps, int size);

#endif // TEMP_API_H