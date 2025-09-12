/*
 * паковать массив
В программе реализована структура данных:
struct pack_array {
uint32_t array; // поле для хранения упакованного массива из 0 и 1
uint32_t count0 : 8; // счетчик нулей в array
uint32_t count1 : 8; // счетчик единиц в array
}
Необходимо реализовать программу, которая упаковывает переданный ей массив из 32-ух элементов 0 и 1 в указанную структуру данных.
Функция должна строго соответствовать прототипу:
 void array2struct(int [], struct pack_array *)

 Примеры:
 Входные данные
 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

 Результат работы:
 4294901760 16 16

 Входные данные
 1 1 1 1 1 1 1 1 1 0 1 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1

 Результат работы:
 4289134601 17 15
 * */

#include <stdio.h>
#include <stdint.h>

struct pack_array {
    uint32_t array;
    uint32_t count0 : 8;
    uint32_t count1 : 8;
};

void array2struct(int arr[], struct pack_array *pack) {
    pack->array = 0;
    pack->count0 = 0;
    pack->count1 = 0;

    for (int i = 0; i < 32; i++) {
        if (arr[i] == 1) {
            pack->array |= (1U << (31 - i));
            pack->count1++;
        } else {
            pack->count0++;
        }
    }
}

int main(void) {
    int arr[32];

    // Читаем 32 числа из входных данных
    for (int i = 0; i < 32; i++) {
        scanf("%d", &arr[i]);
    }

    struct pack_array result;
    array2struct(arr, &result);

    // Выводим результат в требуемом формате
    printf("%u %u %u", result.array, result.count0, result.count1);

    return 0;
}