/*
* ___________________
* Функция по формуле
* ___________________
*
* Описать функцию вычисления f(x) по формуле:
f(x)= x*x при -2 ≤ x < 2;
x*x+4x+5 при x ≥ 2;
4 при x < -2.
Используя эту функцию для n заданных чисел, вычислить f(x).
Среди вычисленных значений найти наибольшее.
*
* _______________________
* Input format
* ______________________
* Последовательность не нулевых целых чисел, в конце последовательности число 0.
*
* ______________________
* Output format
* ______________________
*
* Одно целое число
 * */

#include <stdio.h>

int f(int x);

int main(void) {
    int x=0;
    int first = 1;
    int max_val=0;

    while (scanf("%d", &x) == 1 && x != 0) {
        const int fx = f(x);
        if (first) {
            max_val = fx;
            first = 0;
        } else if (fx > max_val) {
            max_val = fx;
        }
    }

    printf("%d", max_val);
    return 0;
}

int f(const int x) {
    if (x < -2) {
        return 4;
    }

    else if (x < 2) {
        return x * x;
    }

    else {
        return x * x + 4 * x + 5;
    }

}