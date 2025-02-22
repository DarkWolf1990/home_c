/*
_________________
* Модуль числа
_________________

Составить функцию, модуль числа и привести пример ее использования.

___________________
Input format
____________________

Целое число

____________________
Output format
____________________
Целое не отрицательное число */
#include <stdio.h>

int absoluteValue(int num);

int main(void) {
    int number = 0;
    if (scanf("%d", &number) != 1) {
        fprintf(stderr, "Error: Invalid input\n");
        return 1;
    }
    printf("%d", absoluteValue(number));
    return 0;
}

int absoluteValue(int num) {
    return (num < 0) ? -num : num;
}