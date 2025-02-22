/*
_____________
От 1 до N
_____________

Составить рекурсивную функцию, печать всех чисел от 1 до N

_________________
Input format
_________________

Одно натуральное число

_________________
Output format
_________________

Последовательность чисел от 1 до введенного числа

* */

#include <stdio.h>
void recursion(int current, int n);

int main(void) {
    int n = 0;
    scanf("%d", &n);
    recursion(1, n);
    return 0;
}

void recursion(int current, int n) {
    if (current > n) {
        return;
    }
    printf("%d ", current);
    recursion(current + 1, n);
}