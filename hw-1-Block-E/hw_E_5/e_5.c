/*
* _______________________________
* Сумма положительных элементов
* _______________________________
*
 * Считать массив из 10 элементов и посчитать сумму положительных элементов массива.
 *
 * _____________________
* Input format
* ______________________
*
 * 10 целых чисел через пробел
 *
 *____________________
* Output format
* _____________________
*
 * Одно целое число - сумма положительных элементов массива
 * */


#include <stdio.h>

int main(void){
    const int  n=10;
    int numbers[n], sum = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d",&numbers[i]);
    }

    for (int i = 0; i < n; i++) {
        if (numbers[i] > 0){
          sum += numbers[i];
        }

    }

    printf("%d\n",sum);

    return 0;
}
