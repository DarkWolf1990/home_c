/*
* Создание многомодульного консольного приложения:
Создать массив из структурного типа данных для хранения температуры.
Структура типа:  dddd - год 4 цифры mm - месяц 2 символа  dd - день 2 цифры hh - часы 2 цифры mm - минуты 2 цифры temperature - целое число от -99 до 99
Создать прототипы (заглушки) функций вывода статистики по каждому месяцу:  среднемесячная температура, минимальная температура в текущем месяце, максимальная температура в текущем месяце, вывод статистику за год: • среднегодовая температура • минимальная температура • максимальная температура
Все прототипы функций используемые в приложении должны быть вынесены в отдельный файл temp_api.h
Тексты функций - в файл temp_api.c.
Приложение должно собираться при помощи утилиты make

 * */

#include "temp_api.h"
#include <stdio.h>

int main() {

    const int DAYS_IN_YEAR = 365;
    Temperature temps[DAYS_IN_YEAR];

    for (int i = 0; i < DAYS_IN_YEAR; i++) {
        temps[i].year = 2025;
        temps[i].month[0] = '0' + ((i / 30) / 10);
        temps[i].month[1] = '0' + ((i / 30) % 10);
        temps[i].month[2] = '\0';
        temps[i].day[0] = '0' + ((i % 30) / 10);
        temps[i].day[1] = '0' + ((i % 30) % 10);
        temps[i].day[2] = '\0';
        temps[i].hour[0] = '0' + ((i % 24) / 10);
        temps[i].hour[1] = '0' + ((i % 24) % 10);
        temps[i].hour[2] = '\0';
        temps[i].minute[0] = '0' + ((i % 60) / 10);
        temps[i].minute[1] = '0' + ((i % 60) % 10);
        temps[i].minute[2] = '\0';
        temps[i].temperature = i % 100 - 50;
    }


    print_monthly_stats(temps, DAYS_IN_YEAR, 1, 2025);


    print_yearly_stats(temps, DAYS_IN_YEAR, 2025);

    return 0;
}